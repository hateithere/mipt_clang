/* 
Not fully working!
Shitty solution.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	char a[1001] = "", b[1001] = "", c[1002]= "";
	//char* a = (char*)calloc(1001, sizeof(char));
	//char* b = (char*)calloc(1001, sizeof(char));
	//char* c = (char*)calloc(1002, sizeof(char));
	int i;
	char x = '0';
	scanf("%s\n%s", a, b);
	char cf = '0'; /* '0', '1', '$' */

	int len_a = strlen(a);
	int len_b = strlen(b);

	if (len_a < len_b) {
		strcpy(c, a);
		strcpy(a, b);
		strcpy(b, c);
	}

	for (i = 1; i <= len_b; ++i) {
		//printf("len:%d\n", len_a-i);
		//printf("%d: (cf=%c):", i, cf);
		// 0 + 0
		if ((a[len_a-i] == '0') && (b[len_b-i] == '0')) {
			x = cf;
			cf = '0';
		}
		// $ + $
		else if ((a[len_a-i] == '$') && (b[len_b-i] == '$')) {
			if (cf == '0') {
				x = '1';
				cf = '$';
			}
			else if (cf == '1') {
				x = '$';
				cf = '0';
			}
			else if (cf == '$') {
				x = '0';
				cf = '$';
			}
		}
		//1 + 1
		else if ((a[len_a-i] == '1') && (b[len_b-i] == '1')) {
			if (cf == '0') {
				x = '$';
				cf = '1';
			}
			else if (cf == '1') {
				x = '0';
				cf = '1';
			}
			else if (cf == '$') {
				x = '1';
				cf = '0';
			}
		}
		// smth + 0 = same as non-zero
		else if (a[len_a-i] == '0') {
			if (cf == '0') {
				x = b[len_b-i];
				cf = '0';
			}
			else if (cf == '1') {
				if (b[len_b-i] == '0') {
					x = cf;
					cf = '0';
				}
				else if (b[len_b-i] == '1') {
					x = '$';
					cf = '1';
				}
				else if (b[len_b-i] == '$') {
					x = '0';
					cf = '0';
				}
			}
			else if (cf == '$') {
				if (b[len_b-i] == '0') {
					x = cf;
					cf = '0';
				}
				else if (b[len_b-i] == '1') {
					x = '0';
					cf = '0';
				}
				else if (b[len_b-i] == '$') {
					x = '1';
					cf = '$';
				}
			}
		}
		else if (b[len_b-i] == '0') {
			if (cf == '0') {
				x = a[len_a-i];
				cf = '0';
			}
			else if (cf == '1') {
				if (a[len_a-i] == '0') {
					x = cf;
					cf = '0';
				}
				else if (a[len_a-i] == '1') {
					x = '$';
					cf = '1';
				}
				else if (a[len_a-i] == '$') {
					x = '0';
					cf = '0';
				}
			}
			else if (cf == '$') {
				if (a[len_a-i] == '0') {
					x = cf;
					cf = '0';
				}
				else if (a[len_a-i] == '1') {
					x = '0';
					cf = '0';
				}
				else if (a[len_a-i] == '$') {
					x = '1';
					cf = '$';
				}
			}
		}
		// 1 + $
		else if (a[len_a-i] == '$' || b[len_b-i] == '$' ) {
			x = cf;
			cf = '0';
		}
		//printf("%c + %c = %c (cf = %c)\n", a[len_a-i], b[len_b-i], x, cf);
		c[len_a-i] = x;
	}
	for (; i <= len_a; ++i) {
		// 0 + 0
		if ((a[len_a-i] == '0') && (cf == '0')) {
			x = '0';
		}
		// $ + $
		else if ((a[len_a-i] == '$') && (cf == '$')) {
			x = '1';
			cf = '$';
		}
		//1 + 1
		else if ((a[len_a-i] == '1') && (cf == '1')) {
			x = '$';
			cf = '1';
		}
		// smth + 0 = same as non-zero
		else if (a[len_a-i] == '0') {
			x = cf;
			cf = '0';
		}
		else if (cf == '0') {
			x = a[len_a-i];
		}
		// 1 + $
		else if (a[len_a-i] == '$' || cf == '$' ) {
			x = '0';
			cf = '0';
		}

		c[len_a-i] = x;
	}

	c[i] = '\0';
	for (i = 0; c[i] == '0'; ++i);

	//printf("%c\n", cf);

	if (i == len_a) {
		if (cf == '1')
			printf("1");
		else if (cf == '$')
			printf("$");
		else
			printf("0");
	}
	else {
		if (cf != '0') {
			if (cf == '1')
				printf("1%s", c+i);
			if (cf == '$')
				printf("$%s", c+i);
		}
		else
			printf("%s", c+i);
	}
	//free(a);
	//free(b); free(c);
	return 0;
}
