#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[3] = ""; 
	int x;
	strcpy(s, getenv("CODE"));

	x =  strtoq(s, NULL, 16);

	x = x >> 2;
	if (x  & 1)
		printf("ha\n");
	else
		printf("nh\n");
	return 0;
}
