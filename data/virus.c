#include <stdio.h>
#include <stdlib.h>
#define SIZE 12500000

int check_bit(char x, int pos);
int count_bits(char x, int max_offset);

int main() {
	char *robots = (char*)calloc(SIZE, sizeof(char));
	int v, N, i, j, x, s, byte_n, byte, offset;
	int res = 0;

	scanf("%d %d", &v, &N);
	if ((N + 1) % 8) {
		byte_n = (int)((N + 1) / 8) + 1;
	}
	else {
		byte_n = (int)((N + 1) / 8);
	}
	
#ifdef _DEBUG
	printf("byte_n:%d, N;%d\n", byte_n, N);
#endif
	for (i = 0; i < v; ++i) {
		scanf("%d", &x);
		byte = (int)(x / 8);
		offset = x % 8;
#ifdef _DEBUG
		printf("Setting first robot at byte %d[%d]\n!=!=!\n", byte, offset);
#endif
		robots[byte] = robots[byte] | (128 >> offset);
		for (j = 1, s = 0; x * (j + 1) + s  <= N; s += j, ++j) {
#ifdef _DEBUG
			printf("x*%d+%d = %d\n", j+1, s, x * (j+1) + s);
#endif
			byte = (int)((x * (j + 1) + s) / 8);
			offset = (x * (j + 1) + s) % 8;
#ifdef _DEBUG
			printf("Setting byte %d[%d]\n", byte, offset);
#endif
			robots[byte] = robots[byte] | (128 >> offset);
		}
	}
	for (i = 0; i < byte_n - 1; ++i) {
#ifdef _DEBUG
		printf("Counting bits at byte %d, found %d bits\n", i, count_bits(robots[i], 7));
#endif
		res += count_bits(robots[i], 7);
	}
	
	offset = (N - 1) % 8;

#ifdef _DEBUG
	printf("Counting bits at byte %d, found %d bits[final offset: %d]\n", i, count_bits(robots[i], offset), offset);
#endif
	res += count_bits(robots[i], offset);
	printf("%d", res);
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
