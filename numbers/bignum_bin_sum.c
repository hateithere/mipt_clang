#include <stdio.h>
#include <string.h>

int main() {
	char a[1001] = "";
	char b[1001] = "";
	char res[1002] = ""
	char null = 0;
	int len, len_;
	int i, j;
	
	char cf = 0;

	scanf("%s", a);
	scanf("%s", b);

	j = 0;
	if (a[0] == '0') 
		null = 1;
	if (null) {
		for (i = 0; (i <= (int)strlen(a)) && (a[i] != '\0'); ++i) {
	
			if (!null || a[i] != '0') {
				res[j] = a[i];
				++j;
				null = 0;
			}
		}
		strcpy(a, res);
	}
	if (null) {
		a[0] = '0';
		a[1] = '\0';
	}

	null = 0;
	j = 0;
	if (b[0] == '0') 
		null = 1;
	if (null) {
		for (i = 0; (i <= (int)strlen(b)) && (b[i] != '\0'); ++i) {
			if (!null || b[i] != '0') {
				res[j] = b[i];
				++j;
				null = 0;
			}
		}
		strcpy(b, res);
	}
	if (null) {
		b[0] = '0';
		b[1] = '\0';
	}
	if (strlen(a) < strlen(b)) {
		strcpy(res, a);
		strcpy(a, b);
		strcpy(b, res);
	}
	len = strlen(a);
	len_ = strlen(b);
	strcpy(res, b);
	for (i = 0; i < len-len_; ++i) {
		b[i] = '0';
	}
	for (i = 0; i < len_+1; ++i) {
		b[len-i] = res[len_-i];
	}

	for (i = len-1; i >= 0; --i) {
		res[i] = '0' + (a[i] + b[i] - 2 * '0' + cf) % 2;
		cf = (int)((a[i] + b[i] - 2 * '0' + cf) / 2);
	}

	if (cf) {
		putchar('1');
		printf("%s", res);
		return 0;
	}
	printf("%s", res);
	return 0;
}
