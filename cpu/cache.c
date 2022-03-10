#include <stdio.h>
#define N 1024

int gcd(int a, int b);
int main() {
	int n, d;
	int i, j, k;
	/* to use shorter types such as short is a BAD idea */
	static int A[N][N], B[N][N], C[N][N];
	int res = 0;

	scanf("%d %d", &n, &d);
	
	for (i = 0; i < n; ++i)
		for (j = i; j < n; ++j) {
			//printf("%d %d\n", i ,j);
			A[i][j] = gcd(i + 2,j + 2);
			A[j][i] = A[i][j];
		}
	//printf("nya!\n");
	for (i = 0; i < n; ++i)
		for (j = i; j < n; ++j) {
			//printf("%d %d\n", i ,j);
			B[i][j] = gcd(n - i,n - j);
			B[j][i] = B[i][j];
		}

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			for (k = 0; k < n; ++k) {
				//printf("i:%d, j^%d, k^%d\n", i, j, k);
				C[i][j] += A[i][k] * B[j][k];
			}
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (C[i][j] % d == 0)
				++res;

	printf("%d", res);
}

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b % a, a);    
}

