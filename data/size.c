#include <stdio.h>
#include <string.h>

int main() {
	char s;
	int len_f = 0;
	int len_d = 0;
	int len_ld = 0;
	s = getchar();
	
	float xf = 0.5;
	double xd = 0.5;
	long double xld = 0.5;

	for (; (float)1.0 + xf != (float)1.0; ++len_f, xf /= 2);
	for (; 1.0 + xd != 1.0; ++len_d, xd /= 2);
	for (; 1.0 + xld != 1.0; ++len_ld, xld /= 2);
	
	if (s == 'f') {
		printf("%d", len_f);
	}
	if (s == 'd') {
		printf("%d", len_d);
	}
	if (s == 'l') {
		printf("%d", len_ld);
	}

}
