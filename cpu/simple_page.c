#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned N, i, page_n, log;
	
	scanf("%u", &N);
	unsigned *mem = (unsigned*)calloc(N, sizeof(unsigned));
	for (i = 0; i < N; ++i) {
		scanf("%x", &mem[i]);
	}

	scanf("%x", &log);
	page_n = (log >> 26) & 0b111111;
	if (page_n < N) {
		printf("%x", mem[page_n]+(log << 6 >> 6));
	}
	else {
		printf("error");
	}


	free(mem);
	return 0;


}
