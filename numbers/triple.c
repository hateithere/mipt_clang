#include <stdio.h>
#include <string.h>

int pow_(int x, int y) {
	if (!y) {
		return 1;
	}
	int res = x;
	for (int i = 1; i <= y-1; ++i) {
		res = res*x;
	}
	return res;
}
int main() {
	char nya[10000];
	int res = 0;
	scanf("%s", nya);

	int len = strlen(nya);
	for (int i = len-1; i >= 0; --i) {
		res += (nya[i] - '0') * pow_(3, len-i-1);
	}
	printf("%d\n", res);

}


