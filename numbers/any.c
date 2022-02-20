#include <stdio.h>
#include <math.h>
#include <string.h>

int to_dec(char *s, int n);
void to_n(int x, int n, char *res);
void print_reverse(char *s);

int main() {
	int n, k;
	char A[1000];
	char res[1000] = "";
	scanf("%d\n%s\n%d", &n, A, &k);
	if ((strlen(A) == 1) && (A[0] == '0')) {
		printf("0\n");
		return 0;
	}
	n = to_dec(A, n);
	to_n(n, k, res);
	print_reverse(res);
	return 0;
}

void to_n(int x, int n, char *res) {
	int a, b;
	int i;
	a = x;
	for (i = 0; a > 0; ++i) {
		b = a % n;
		a = (int)(a / n);
		if (b < 10) {
			res[i] = '0' + b;
		}
		else {
			res[i] = 'A' + b - 10;
		}
	}
	res[i] = '\0';
}

int to_dec(char *s, int n) {
	int len = strlen(s);
	int res = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (s[i] >= '0' && s[i] <= '9') {
			res += (s[i] - '0') * pow(n, len-i-1);
		}
		else {
			res += (s[i] - 'A' + 10) * pow(n, len-i-1);
		}
	}
	return res;
}

void print_reverse(char *s) {
	for (int i = strlen(s) - 1; i >= 0; --i) {
		printf("%c", s[i]);
	}
	putchar('\n');
}
