#include <stdio.h>
#include <stdlib.h>
#define SIZE 12500000

int check_bit(char x, int pos);
int count_bits(char x, int max_offset);

int main() {
	/*
	Info about every number is stored into BITS of char elements, so we can have 8 * SIZE numbers. Not including numbers divided by 2, they aren't prime by design.
	Array start: {1, 2, 3, 5, 7 ...} at sieve[0]
	*/
	char *sieve = (char*)calloc(SIZE, sizeof(char));
	int N, i, j, byte, offset, in_offset, in_byte, num, byte_n;
	int res = 0;
	scanf("%d", &N);
	int n = N;
	if (N % 2) {
		N = (N + 1) / 2 + 1;
	}
	else {
		N = N / 2 + 1;
	}
	if (N % 8) {
		byte_n = (int)(N / 8) + 1;
	}
	else {
		byte_n = (int)(N / 8);
	}
#ifdef _DEBUG
	printf("byte_n[%d], N[%d]\n", byte_n, N);
#endif
	/* Initialization of used numbers by 1 (bits of every char, char is 1 byte) */
	for (i = 0; i < byte_n; ++i)
		sieve[i] = 255;
	
	/* Starting from 3 */
	for (i = 2; i * i <= N; ++i) {
		offset = i % 8;
		byte = (int) (i / 8);
#ifdef _DEBUG
//printf("Byte:%d[offset:%d]\n", byte, offset);
		printf("Check %d[%d] - %d\n", byte, offset, check_bit(sieve[byte], offset));
#endif
		if (check_bit(sieve[byte], offset)) {
			num = i + (i - 1);
			for (j = num + 2 * num; j < n; j += 2 * num) {
#ifdef _DEBUG
				printf("i[%d], j[%d]. step: %d\n", i, j, 2 * num);
#endif
				in_offset = (int)((j + 1) / 2) % 8;
				in_byte = (int)((int)((j + 1) / 2) / 8);
				//in_offset = (i + j) % 8;
				//in_byte = (int) ((i + j) / 8);
				
#ifdef _DEBUG
				printf("Zeroing %d[%d]\n!=!=!\n", in_byte, in_offset);
#endif
				/* 128 = 1000000 */
				sieve[in_byte] = sieve[in_byte] & ~(128 >> in_offset);
			}
		}
	}


	for (i = 0; i < byte_n - 1; ++i) {
#ifdef _DEBUG
		printf("Counting bits at byte %d, found %d bits\n", i, count_bits(sieve[i], 7));
#endif
		res += count_bits(sieve[i], 7);
	}
	
	offset = (N - 1) % 8;

#ifdef _DEBUG
	printf("Counting bits at byte %d, found %d bits[final]\n", i, count_bits(sieve[i], offset));
#endif
	res += count_bits(sieve[i], offset);
	printf("%d", --res);
}

int check_bit(char x, int pos) {
	return (x >> (7 - pos)) & 1;
}

int count_bits(char x, int max_offset) {
	int res = 0;
	for (int i = 0; i <= max_offset; ++i) {
		res += check_bit(x, i);
	}
	return res;
}
