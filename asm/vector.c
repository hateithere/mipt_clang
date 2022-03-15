#include <stdio.h>
#include <stdint.h>

int main() {
	//uint64_t c = 5;
	uint64_t b, c = 5;
	int64_t *a;
	int64_t array[] = {1, 2, 3, 4, 5};
	a = array;
	//printf("pointer: %p\n", a);
	asm (
		"mov %1, %%rax\n"
		"mov %2, %%rcx\n"

		"xor %%rbx, %%rbx\n"
		"cmp $0, %%rcx\n"
		"je end\n"
		
		"dec %%rcx\n"

		"loop:\n"

		"lea (%%rax, %%rcx, 8), %%rdx\n"
		"add (%%rdx), %%rbx\n"
		"dec %%rcx\n"

		"cmp $-1, %%rcx\n"
		"je end\n"
		"jmp loop\n"

		"end:\n"


		"mov %%rbx, %0\n"
		: "=r" (b)
		: "r" (a), "r" (c)
	    );
	printf("%lld\n", b);

}
