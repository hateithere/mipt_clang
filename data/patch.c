#ifdef _DEBUG
#include <stdio.h>
unsigned int patch(unsigned int x);

int main() {
	unsigned int x = 1000 * 100;
	unsigned int y = 2310 * 100 + 72;
	unsigned int z = patch(y);
	return 0;
}

#endif

unsigned int patch(unsigned int x) {
	return x & ~(1 << 17);
}
