#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ROTL8(x, shift) ((uint8_t)((x) << (shift)) | ((x) >> (8 - (shift))))

void initialize_aes_sbox(uint8_t sbox[256])
{
	uint8_t p = 1, q = 1;

	/* loop invariant: p * q == 1 in the Galois field */
	do
	{
		/* multiply p by 3 */
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);

		/* divide q by 3 (equals multiplication by 0xf6) */
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		q ^= q & 0x80 ? 0x09 : 0;

		/* compute the affine transformation */
		uint8_t xformed = q ^ ROTL8(q, 1) ^ ROTL8(q, 2) ^ ROTL8(q, 3) ^ ROTL8(q, 4);

		sbox[p] = xformed ^ 0x63;
	} while (p != 1);

	/* 0 is a special case since it has no inverse */
	sbox[0] = 0x63;
}

int main()
{
	// initialize s box
	uint8_t sbox[256];
	initialize_aes_sbox(sbox);

	unsigned char temp;
	unsigned char *b;

	unsigned char zero_one = 0x01;

	unsigned int k[4][4] = {{0x00, 0x00, 0x00, 0x00},
							{0x00, 0x00, 0x00, 0x00},
							{0x00, 0x00, 0x00, 0x00},
							{0x00, 0x00, 0x00, 0x00}};

	for (unsigned int i = 0; i < 255; i++)
	{
		k[0][0] = i;

		temp = k[0][0] ^ zero_one;
		// printf("before : %x\n", temp);
		// printf("%x\n", temp);

		// sub bytes
		temp = sbox[temp];
		// printf("after : %x\n", temp);
		// printf("%x\n", temp);

		for (int j = 0; j < 4; j++)
		{
			for (int x = 0; x < 4; x++)
			{
				k[j][x] = sbox[k[j][x]];
			}
		}

		// printf("before : %x\n", k[0][0]);
		// printf("before : %x\n", temp);
		k[0][0] = k[0][0] * 0x02;
		temp = temp * 0x02;

		/////////////////////// reduction /////////////////////////////
		while (temp > 0xff){
			temp = temp ^ 0x1b;
		}
		while (k[0][0] > 0xff){
			k[0][0] = k[0][0] ^ 0x1b;
		}
		////////////////////// reduction //////////////////////////////

		// printf("after  : %x\n", temp);
		// printf("after :  %x\n", k[0][0]);

		printf("XOR temp: %x\n", temp);
		printf("XOR k: %x\n", k[0][0]);

		unsigned char ans = temp ^ k[0][0];

		if (ans > 0xff){
			ans = ans ^ 0x1b;
		}

		printf("XOR: %x\n\n", ans);

		if ( ans == 0x02)
		{
			printf("HELLO???? : %x\n", i);
		}
	}
	return 0;
}