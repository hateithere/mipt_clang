#include <stdio.h>

int main() {
	short a, b, c, d;
	scanf("%hd %hd", &a, &b);
	asm
		(			
		 	"mov %1,%%ax\n"
			"mov %2,%%bx\n"
		 	"cwd\n"
			"idiv %%bx\n"
			"mov %%ax, %%dx\n"
			"mov %%dx, %0\n"
			: "=r" (c)
			: "r" (a), "r" (b)
		);
	printf("%hd\n", c);
}


