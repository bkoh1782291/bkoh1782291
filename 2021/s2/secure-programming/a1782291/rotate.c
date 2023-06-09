#include <stdio.h>
#include <stdint.h>

#define BITS 32

uint32_t rotate(uint32_t number, uint32_t count){

	uint32_t res = 0;
	uint32_t bits = (BITS - count);

	res = (number << count) | (number >> bits);

	return res;
}
