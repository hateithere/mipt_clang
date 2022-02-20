#include <stdio.h>


int is_equal(const int *a, int n);

int main() {
	int a[3];
	int n = 0;
	int res = 0;
	scanf("%d", &n);
	
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) {
				a[0] = i;
				a[1] = j;
				a[2] = k;
				if (is_equal(a, n))
					res = i * n * n + j * n + k;
			}
	printf("%d", res);
	
	return 0;
}
int is_equal(const int* a, int n) {
	long long q1 = 1ll* a[0] * n * n + a[1] * n + a[2];
	long long q2 = q1 * q1;
	
	if (q2 % n == a[2] && (q2 / n) % n == a[1] && (q2 / (n * n)) % n == a[0])
		return 1;
	
	return 0;
}
