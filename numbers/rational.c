#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	char s[31] = "";
	int i;
	double res = 0;
	char irnull = 0;
	char r[31], ir[31];
	scanf("%s", s);
	
	for (i = 0; i < 31; ++i) {
		if (s[i] == '.') {
			s[i] = '\0';
			break;
		}
	}
	
	++i;

	strcpy(r, s);

	if (i < 32) {
		strcpy(ir, s+i);
	}
	else {
		irnull = 1;
	}
	
	// Перевод целой части	
	int len = strlen(r); 
	for (i = 0; i < len; ++i) {
		res += (r[i] - '0') * pow(2, len-i-1);
	}
	
	// Если дробная часть есть, то переводим и её
	if (!irnull) {
		len = strlen(ir); 
		for (i = 1; i < len+1; ++i) {
			res += (ir[i-1] - '0') * pow(2, -i);
		}
	}

	printf ("%.12lf", res);
	return 0;
}
