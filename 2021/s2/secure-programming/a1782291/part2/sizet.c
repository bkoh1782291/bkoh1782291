#include <stdint.h>
#include <stdio.h>
#define O(type, field) (size_t)(&(((type *)0)->field))

struct byname {
	int16_t int16;
	int32_t int32;
	int64_t int64;
	int8_t int8;
	intptr_t intptr;
	uint16_t uint16;
	uint32_t uint32;
	uint64_t uint64;
	uint8_t uint8;
	uintptr_t uintptr;
};
struct bysize {
	int8_t int8;	   // 1
	uint8_t uint8;	   // 1
	int16_t int16; 	   // 2
	uint16_t uint16;   // 2
	int32_t int32;	   // 4
	uint32_t uint32;   // 4
	int64_t int64;	   // 8
	uint64_t uint64;   // 8
	intptr_t intptr;   // 8
	uintptr_t uintptr; // 8
};

int main() {
	printf("By size: %d\n", sizeof(struct bysize));
	printf("By name: %d\n", sizeof(struct byname));
}
