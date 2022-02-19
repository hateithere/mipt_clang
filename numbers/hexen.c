#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 4000001

int main() {
	char x;
	char* res = (char*)calloc(MAXLEN, sizeof(char));
	
	char buf[5] = "";
	int i, len;

	len = 0;

	while (((x = getchar()) != '\n' ) && (x != EOF)) {
		switch (x) {
			case '0':
				strcpy(buf, "0000");
				break;
			case '1':
				strcpy(buf, "0001");
				break;
			case '2':
				strcpy(buf, "0010");
				break;
			case '3':
				strcpy(buf, "0011");
				break;
			case '4':
				strcpy(buf, "0100");
				break;
			case '5':
				strcpy(buf, "0101");
				break;
			case '6':
				strcpy(buf, "0110");
				break;
			case '7':
				strcpy(buf, "0111");
				break;
			case '8':
				strcpy(buf, "1000");
				break;
			case '9':
				strcpy(buf, "1001");
				break;
			case 'A':
				strcpy(buf, "1010");
				break;
			case 'B':
				strcpy(buf, "1011");
				break;
			case 'C':
				strcpy(buf, "1100");
				break;
			case 'D':
				strcpy(buf, "1101");
				break;
			case 'E':
				strcpy(buf, "1110");
				break;
			case 'F':
				strcpy(buf, "1111");
				break;
		}

		for (i = 0; i < 4; ++i) {
			res[len++] = buf[i];
		}
	}
	
	for (i = 0; res[i] == '0'; ++i);
	if (i == len) {
		printf("0\n");
		free(res);
		return 0;
	}
	printf("%s\n", res+i);
	free(res);
	return 0;
}
