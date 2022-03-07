#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000000

int f(const void *a, const void *b);

int main() {
	static long double nums[SIZE];
	int len, i;
	long double x;
	long double sum = 0;

	for (len = 0; scanf("%Lf", &x) != EOF; ++len) {
		nums[len] = x;
	}
	qsort(nums, len, sizeof(long double), f);

#ifdef _DEBUG
	for (int z = 0; z < len; ++z)
		printf("%.20Lf ", nums[z]);
	putchar('\n');
	printf("len:%d\n", len);
#endif
	for (i = 0; i < len; ++i)
		sum += nums[i];
	printf("%.20Lf", sum);

}

int f(const void *a, const void *b) {
#ifdef _DEBUG
	printf("a = %f, b = %f\n", *(float *)a, *(float *)b);
#endif
	if (*(const long double *)a > *(const long double *)b)	
		return 1;
	return -1;
}
