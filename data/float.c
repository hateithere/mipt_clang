#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000000

int euclid(int a, int b);

int main() {
	float f;
	char p = 0;
	static char s[SIZE] = "";
	static char x[SIZE] = "", y[SIZE] = "", z[SIZE] = "";
	int i, j;
	int xi = 0, yi = 0, zi = 0, gcd = 1;
	scanf("%f", &f);
	sprintf(s, "%.6f", f);
	
	for (i = 0; (i < (int)strlen(s)) && (s[i] != '.'); ++i);

	for (j = 0; j < i; ++j)
		x[j] = s[j];

	for (j = 0; j < (int)strlen(s); ++j) {
		y[j] = s[i+1+j];
		if ((y[j] != '0') && (y[j] != '\0'))
			p = 1;
	}
	
	if (p)
		for (j = 0; j < (int)strlen(s) - i; ++j)
			z[j] = '0';
	else {
		z[0] = '1';
		z[1] = '\0';
	}
		
	if (j) {
		z[0] = '1';
		z[j] = '\0';
	}
	else {
		y[0] = '0';
		y[1] = '\0';
		z[0] = '1';
		z[1] = '\0';
	}

	xi = atoi(x);
	yi = atoi(y);
	zi = atoi(z);
	if (zi != 0)
		gcd = euclid(zi, yi);

	if (gcd) {
		zi = (int) zi / gcd;
		yi = (int) yi / gcd;
	}
	if (zi == 0)
		zi = 1;
	printf("%d (%d/%d)", xi, yi ,zi);
}

int euclid(int a, int b) {
	if ((a == 0) || (b == 0))
		return 0;
	int x = 1;
	if (a < b) {
		int c = a;
		a = b;
		b = c;
	}

	while (x != 0) {
		x = a % b;
		a = x;	
		if (a < b) {
			int c = a;
			a = b;
			b = c;
		}
	}
	return a;
}
