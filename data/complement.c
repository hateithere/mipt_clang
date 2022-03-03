#include <stdio.h>

int main() {
	int i;
	char y;
	scanf("%hhd", &y);

	if (y < 0)
		y = ~(-y) + 1;

	for (i = 7; i >= 0; --i) {
		printf("%d", (y >> i) & 1);
	}
	return 0;
}
