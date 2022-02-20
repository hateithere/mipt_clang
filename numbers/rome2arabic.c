#include <stdio.h>
#include <string.h>
#define LEN 7

const char rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int arabic[] = {1, 5, 10, 50, 100, 500, 1000};

int find_eq(char c);

int main() {
	int cur, next;
	int res = 0;
	int i;
	char s[4000];

	scanf("%s", s);
	
	for (i = 0; i < (int)strlen(s) - 1; ++i) {
		cur = find_eq(s[i]);
		next = find_eq(s[i+1]); 
		if (cur < next) {
			res -= cur;
		}
		else 
			res += cur;
	}

	res += find_eq(s[i]);

	printf("%d", res);
	return 0;
}

int find_eq(char c) {
	int i;
	for (i = 0; (c != rome[i]) && (i < LEN); ++i);	
	return arabic[i];
}
