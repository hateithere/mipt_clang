#include <stdio.h>
#include <string.h>

void print_permission(char *s);
int main() {
	int i;
	char res[10] = "";
	char x[4] = "";
	char buf[4] = "";
	scanf("%s", x);
	
	for (i = 0; i < 3; ++i) {
		switch (x[i]) {
			case '0':
				buf[0] = '0';
				buf[1] = '0';
				buf[2] = '0';
				break;
			case '1':
				buf[0] = '0';
				buf[1] = '0';
				buf[2] = '1';
				break;
			case '2':
				buf[0] = '0';
				buf[1] = '1';
				buf[2] = '0';
				break;
			case '3':
				buf[0] = '0';
				buf[1] = '1';
				buf[2] = '1';
				break;
			case '4':
				buf[0] = '1';
				buf[1] = '0';
				buf[2] = '0';
				break;
			case '5':
				buf[0] = '1';
				buf[1] = '0';
				buf[2] = '1';
				break;
			case '6':
				buf[0] = '1';
				buf[1] = '1';
				buf[2] = '0';
				break;
			case '7':
				buf[0] = '1';
				buf[1] = '1';
				buf[2] = '1';
				break;
		}
		buf[3] = '\0';
		strcpy(res + 3*i, buf);
	}
	res[9] = '\0';

	print_permission(res);

	return 0;
}


void print_permission(char *s) {
	//for (int i = strlen(s) - 1; i >= 0; --i) {
	for (int i = 0; i < (int)strlen(s); ++i) {
		if (s[i] != '0') {
			if ((i + 1) % 3 == 0)
				putchar('x');
			else if ((i + 1) % 3 == 1)
				putchar('r');
			else
				putchar('w');
		}
		else
			putchar('-');

	}
	putchar('\n');
}
