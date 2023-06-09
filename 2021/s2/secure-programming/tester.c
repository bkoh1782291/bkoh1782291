#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rsa.c"

int main(int ac, char **av) {
	num_t m, n, e, c, d;
	printf("begin\n");
	num_fromString(m, "2d"); //av[1]
	num_fromString(e, "10001");
	num_fromString(n, "cd7ddeca6ca50a39f2bc0e780478864be17a31ab04aa553b924cf8ddedb62fa9a88be62dbf14d3811d03e0d9313a9918cb9a392f1731586ffbcaa2eed10ff363c4153fb0d5653e83a1be11ac6d4b4e10f6c0afb24af9243ff85a804e5a4114bf4306fe0e36840f22dade71103482eaf54ed51cfda222ee4e5a2640d934b0d4d3");
	num_fromString(d, "2e17899d85f90eee28901dfeb5a2031d8a19ca823dada728918c4a561d37bc4125d91b6c2f6c1074e979313a065cca725158ea72b19513ed2a612d62bbea04017942710c1e596a533b7c9d19db2d4c0cfd386124983a158b3fcc58471ecfb5e949361494c32164dac4b383967777ec01369d1b87462f5148b04b71f58ddf15c1");

	printf("about to enter pkcs\n");
	uint8_t *message = "ja";

	rsa_pkcs_encrypt(c, message, 2, e, n);

	uint8_t *messagebuf;
	// rsa_pkcs_decrypt(messagebuf, 0, c, d, n);
	// num_modexp(c, m, e, n);
	// printf("Main Function: %s\n", num_toString(c));
	exit(0);
}