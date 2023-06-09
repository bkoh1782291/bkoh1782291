#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#ifndef BITSIZE
#define BITSIZE 1024
#endif

#define BYTESIZE ((BITSIZE + 7) / 8)
#define WORDSIZE ((BYTESIZE + sizeof(uint32_t) - 1) / sizeof(uint32_t))

/*
 * Represents a number BITSIZE bits wide.
 * Implemented as an array of int32_t in little endian order.  That is,
 * num = \sum 2^{32*i}*array[i]
 */
typedef uint32_t num_t[WORDSIZE];

/*
 * Represents a number 2*BITSIZE bits wide
 * Same format as num_t, only twice as long
 */
typedef uint32_t bignum_t[WORDSIZE * 2];

/*
 * Converts a num_t to a hexadecimal string. The memory for the string is allocated
 * with malloc and needs to be freed after use.
 */
char *num_toString(const num_t n);

/*
 * Converts a hexadecimal string (without 0x) to a num_t.
 */
int num_fromString(num_t in, const char *s);

/* Computes res = n1 + n2.  Returnes the carry */
uint32_t num_add(num_t res, const num_t n1, const num_t n2);

/* Computes res = n1 * n2. */
void num_mul(bignum_t res, const num_t n1, const num_t n2);

/* Computes res = n^2. */
void num_square(bignum_t res, const num_t n);

/* Trims a bignum_t n to num_t */
void num_trim(num_t res, const bignum_t n);

/* Computes numerator/denominator. Returns the quotient and the remainder. */
int num_div(bignum_t quotient, num_t remainder, const bignum_t numerator, const num_t denominator);

/******************************************************************************\
*                   IMPLEMENT THE THREE FUNCTIONS BELOW                        *
\******************************************************************************/

/* Calculates res = base ^ exp modulo mod */
void num_modexp(num_t res, const num_t base, const num_t exp, const num_t mod)
{
	// initialising res
	res[0] = 1;
	for (int i = 1; i < 32; ++i)
	{
		res[i] = 0;
	}

	int counter = 0;
	char *exp_string = num_toString(exp);
	int size_arr = strlen(exp_string);

	// count number of leading zeros
	for (int i = 0; i < size_arr; i++)
	{
		if (exp_string[i] != '0')
		{
			break;
		}
		counter = counter + 1;
	}

	int numb_size = size_arr - counter;

	// allocate memory for new array
	char *numb = malloc(numb_size);
	int b_counter = 0;

	// copying contents to new array
	for (int i = counter; i < size_arr; i++)
	{
		if (exp_string[i] != '0')
		{
			numb[b_counter] = exp_string[i];
			b_counter++;
		}
	}

	// convert numb to int
	int dec = atoi(numb);

	//converting the decimal into a binary
	int binary_arr[1024] = {0};

	int z = 0;
	while (dec > 0)
	{
		binary_arr[z] = dec % 2;
		dec = dec / 2;
		z++;
	}

	//computing the result from res = base ^ exp modulo mod
	res[0] = 1;
	bignum_t temp = {0};
	bignum_t temp2 = {0};

	for (int i = BITSIZE - 1; i > -1; i--)
	{
		num_square(temp, res);
		num_trim(res, temp);
		int useless = num_div(temp2, res, temp, mod);
		if (binary_arr[i] == 1)
		{
			num_mul(temp, res, base);
			num_trim(res, temp);
			int useless = num_div(temp2, res, temp, mod);
		}
	}
}

/*
 * Pads message using PKCS#1 v1.5 and encrypts with a public RSA key (n, e)
 * Returns 0 on success and 1 on failure.
 *
 * You can assume that n is full size, i.e. n>=2^{BITSIZE - 1}
 */
int rsa_pkcs_encrypt(num_t ciphertext, const uint8_t *message, int messagelen, const num_t e, const num_t n)
{
	// sanity check
	if (messagelen > 117)
	{
		return 1;
	}

	char *array = malloc(256);
	strcat(array, "0002");

	// number of spare bytes to allocate
	int r = (128 - 3 - messagelen);
	// empty arrays for sprintf and strcat functions
	char l_array[3];

	// generate random numbers and concatenate into new array
	for (int i = 0; i < r; i++)
	{
		int num = rand() % 255 + 1; // 1 to 255
		sprintf(l_array, "%02x", num);
		strcat(array, l_array);
	}

	char k_arr[2 * messagelen]; // size 4

	// convert message to hex
	for (int i = 0, j = 0; i < messagelen; i++, j += 2)
	{
		sprintf(k_arr + j, "%02x", message[i] & 0xff);
	}

	strcat(array, "00");
	strcat(array, k_arr);

	// printing out encrypted array
	printf("%s\n", array);

	num_t in;
	int arr = num_fromString(in, array);

	// call to numbmodexp
	num_modexp(ciphertext, in, e, n);

	return 0;
}

/*
 * Decrypts ciphertext using (n, d) and verifies that it is in PKCS#1 v1.5 format.
 * If the format is correct, writes the message in messagebuf and returns the
 *    message length. If the length of the decrypted message is larger than
 *    messagebuflen, only the first messagebuflen bytes of the message are written.
 * If the message is not in PKCS#1 v1.5 format, returns -1.
 * In case of other errors, returns -2.
 *
 * You can assume that n is full size, i.e. n>=2^{BITSIZE - 1}
 */
int rsa_pkcs_decrypt(uint8_t *messagebuf, int messagebuflen, const num_t ciphertext, const num_t d, const num_t n)
{
	return 0;
}

/******************************************************************************\
*                     DO NOT MODIFY BELOW THIS LINE                            *
\******************************************************************************/

uint32_t num_add(num_t res, const num_t n1, const num_t n2)
{
	uint64_t s = 0ULL;
	for (int i = 0; i < WORDSIZE; i++)
	{
		s += (uint64_t)n1[i] + (uint64_t)n2[i];
		res[i] = s & 0xffffffffULL;
		s >>= 32;
	}
	return (uint32_t)s;
}

void num_mul(bignum_t res, const num_t n1, const num_t n2)
{
	for (int i = 0; i < WORDSIZE * 2; i++)
		res[i] = 0;

	for (int i = 0; i < WORDSIZE; i++)
	{
		uint64_t s = 0;
		for (int j = 0; j < WORDSIZE; j++)
		{
			s += (uint64_t)res[i + j] + (uint64_t)n1[i] * (uint64_t)n2[j];
			res[i + j] = s & 0xffffffffULL;
			s >>= 32;
		}
		res[i + WORDSIZE] += s;
	}
}

void num_trim(num_t res, const bignum_t n)
{
	for (int i = 0; i < WORDSIZE; i++)
		res[i] = n[i];
}

static uint32_t shiftleft(uint32_t *a, const uint32_t *b, int n, int d)
{
	uint64_t carry = 0;
	for (int i = 0; i < n; i++)
	{
		carry |= ((uint64_t)b[i]) << d;
		a[i] = carry & 0xFFFFFFFFULL;
		carry >>= 32;
	}
	return carry;
}

static uint64_t Step_D3(uint32_t *uj, uint32_t *v, int n)
{
	uint64_t hat = ((uint64_t)uj[n] << 32) + uj[n - 1];
	uint64_t qhat = hat / v[n - 1];
	uint64_t rhat = hat % v[n - 1];
	if (qhat == 0x100000000ULL || (n > 1 && (qhat * v[n - 2] > 0x100000000ULL * rhat + uj[n - 2])))
	{
		qhat--;
		rhat += v[n - 1];
		if (rhat < 0x100000000ULL && n > 1 && (qhat * v[n - 2] > 0x100000000ULL * rhat + uj[n - 2]))
		{
			qhat--;
			rhat += v[n - 1];
		}
	}
	return qhat;
}

static uint32_t Step_D4(uint32_t *uj, uint32_t *v, uint64_t qhat, int n)
{
	uint64_t borrow = 0;
	for (int i = 0; i < n; i++)
	{
		borrow += uj[i];
		borrow -= qhat * v[i];
		uj[i] = borrow & 0xFFFFFFFFULL;
		borrow >>= 32;
		if (borrow)
			borrow |= 0xFFFFFFFF00000000ULL; // The borrow is always non-positive...
	}
	borrow += uj[n];
	uj[n] = borrow & 0xFFFFFFFFULL;
	return borrow >> 32; // The return value is 16 bits, so no need for extending the sign bit
}

static void Step_D6(uint32_t *uj, uint32_t *v, int n)
{
	uint64_t carry = 0;
	for (int i = 0; i < n; i++)
	{
		carry += uj[i];
		carry += v[i];
		uj[i] = carry & 0xFFFFFFFFULL;
		carry >>= 32;
	}
	carry += uj[n];
	uj[n] = carry & 0xFFFFFFFFULL;
	//assert(carry > 0xFFFF); // We ignore further carry
}

static void shiftright(uint32_t *u, int n, int d)
{
	if (d == 0)
		return;
	for (int i = 0; i < n; i++)
		u[i] = (u[i] >> d) | (u[i + 1] << (32 - d));
	u[n] >>= d;
}

static int reallen(const uint32_t *u, int l)
{
	while (l-- > 0)
	{
		if (u[l] != 0)
			return l + 1;
	}
	return 0;
}

// Using Algorithm 4.3.1 D of Knuth TAOCP
int num_div(bignum_t quotient, num_t remainder, const bignum_t numerator, const num_t denominator)
{
	// Use Knuth's variable names:
	//   u -- numerator
	//   v -- denominator
	//   q -- quotient
	//   d -- normalisation factor
	//   n -- length of denominator
	//   m -- length difference between numerator and denominator
	//   b -- base = 0x100000000
	// Our base (b) is 2^32, so we can use the shift method to calculate d.
	// We use the space of the remainder for the normalised numerator, so
	// need to allocate another variable for that.
	if (quotient == numerator ||
		remainder == denominator)
		return -1;

	// Step D1
	int n = reallen(denominator, WORDSIZE);
	if (n == 0)
		return -1;
	int d = 0;
	uint32_t t = denominator[n - 1];
	assert(t != 0); // This is OK from the calculation of n
	while ((t & 0x80000000) == 0)
	{
		t <<= 1;
		d++;
	}
	num_t vbn;
	memset(vbn, 0, sizeof(num_t));
	uint32_t *v = vbn;
	t = shiftleft(v, denominator, n, d);
	assert(t == 0);

	int nl = reallen(numerator, WORDSIZE * 2);
	int m = nl < n ? 0 : nl - n;

	memset(remainder, 0, sizeof(num_t));
	uint32_t ubn[2 * WORDSIZE + 1];
	memset(ubn, 0, sizeof(ubn));
	uint32_t *u = ubn;
	u[nl] = shiftleft(u, numerator, nl, d);

	uint32_t *q = quotient;

	// Steps D2, D7
	for (int j = m; j >= 0; j--)
	{
		// Step D3
		uint64_t qhat = Step_D3(u + j, v, n);

		// Step D4
		uint32_t borrow = Step_D4(u + j, v, qhat, n);

		// Step D5
		q[j] = qhat;
		if (borrow)
		{
			//Step D6
			assert(qhat != 0);
			Step_D6(u + j, v, n);
			q[j]--;
		}
	}

	// Step D8
	assert((u[0] & ((1 << d) - 1)) == 0);
	shiftright(u, n, d);
	for (int i = m + 1; i < WORDSIZE * 2; i++)
		q[i] = 0;
	for (int i = n + 1; i < WORDSIZE; i++)
		ubn[i] = 0;
	num_trim(remainder, ubn);

	return 0;
}

int num_fromString(num_t in, const char *s)
{
	num_t tmp = {0};
	for (int i = 0; i < WORDSIZE; i++)
		in[i] = 0;

	while (*s)
	{
		if (!isxdigit(*s))
			return -1;
		int c;
		if (isdigit(*s))
			c = *s - '0';
		else if islower (*s)
			c = *s - 'a' + 10;
		else
			c = *s - 'A' + 10;
		shiftleft(tmp, in, WORDSIZE, 4);
		memcpy(in, tmp, sizeof(num_t));
		in[0] += c;
		s++;
	}
	return 0;
}

char *num_toString(const num_t n)
{
	char *rv = malloc(2 * BYTESIZE + 1);
	if (rv == NULL)
		return NULL;
	char *p = rv;
	for (int i = WORDSIZE; i--;)
	{
		if (n[i] == 0)
			continue;
		sprintf(p, "%08X", n[i]);
		p += sizeof(uint32_t) * 2;
	}
	if (p == rv)
		*p++ = '0';
	*p = 0;
	return rv;
}

void num_square(bignum_t res, const num_t n)
{
	num_mul(res, n, n);
}
