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

int main(int argc, char *argv[]) {
	char z[10000];
	if (argc)
		strcpy(z, argv[1]);
	
	float x; 
	int y;
	scanf("%f %x", &x, &y);
	
	int len = strlen(z);
	int res = 0;
	for (int i = len-1; i >= 0; --i) {
		if (z[i]>=48 && z[i]<=57) {
			res += (z[i] - '0') * pow_(27, len-i-1);	
		}
		else {
			res += (z[i] - 54) * pow_(27, len-i-1);
		}
	}
	printf("%.3f\n", x+y+res);
}


