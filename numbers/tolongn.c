#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *dig;
	int n;
	char sign;
} LongN;

LongN getLongN(char * s);
void printLong(LongN x); 
int main() {
	LongN a;
	a.dig = (char*)calloc(101, sizeof(char));
	a.dig[0] = 12;
	a.dig[1] = 34;
	a.dig[2] = 5;
	a.n = 5;
	a.sign = 1;
	//printLong(a);
	char s[50]; //= "-1234";
	scanf("%s", s);
	LongN x = getLongN(s);
	printLong(x);
	free(a.dig);
	free(x.dig);
	return 0;
}

void printLong(LongN x) {
	if (x.sign) {
		printf("-");
	}
	if (x.n % 2) {
		x.n++;
	}
	for (int i = 0; i < (int)(x.n/2); ++i) {
		printf("%d", x.dig[i]);
	}
	printf("\n");
}

LongN getLongN(char* s) {
	int k = 0;
	LongN r;

	r.sign = 0;
	if (s[0] == '-') {
		k = 1;
		r.sign = 1;
	}
	if (s[0] == '+')
		k = 1;

	int l = k;

	for (; s[l] >= '0' && s[l] <= '9'; ++l);
	r.n = (l - k - 1) / 2 + 1;
	r.dig = (char*)calloc(101, sizeof(char));

	int t = 0;
	for (int i = l - 1; i >= k; i -= 2, t++) {
		if (i == k) {
			r.dig[t] = s[i] - '0';
		}
		else 
			r.dig[t] = 10 * (s[i - 1] - '0') + s[i] - '0';
	}
	return r;
}
