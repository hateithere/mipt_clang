#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "sorts.c"
#define ALEN 1000
#define DISPLEN 25
#define THRESHOLD 25

int main() {
	srand(time(NULL));
	int a[ALEN];
	for (int i = 0; i < ALEN; a[i++] = rand() % (2 * ALEN));

	printf("Before:\n");
	for (int i = 0; i < DISPLEN; ++i) {
		printf("%d ", a[i]);
	}
	putchar('\n');

	//bubblesort(a, ALEN);
	insertion(a, ALEN);
	printf("After:\n");
	for (int i = 0; i < DISPLEN; ++i) {
		printf("%d ", a[i]);
	}
	putchar('\n');

	return 0;
}
