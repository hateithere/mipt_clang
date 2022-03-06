#include <stdio.h>
#define SIZE 10000000
//#define _DEBUG

const char base64[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

int main() {
	int i, j;
	char sixtet;

	freopen("data", "rb", stdin);
	freopen("base64", "w", stdout);

	static char x[3*SIZE] = "";
	static char y[4*SIZE] = "";

	int n = fread(x, sizeof(char), 3 * SIZE, stdin) / 3;
	for (i = 0, j = 0; i < 3 * n; i += 3, j += 4) {

		sixtet = (x[i] & 0b11111100) >> 2;
		y[j] = base64[(int)sixtet];
		sixtet = ((x[i] & 0b00000011) << 4) | ((x[i+1] & 0b11110000) >> 4);
		y[j+1] = base64[(int)sixtet];
		sixtet = ((x[i+1] & 0b00001111) << 2) | ((x[i+2] & 0b11000000) >> 6);
		y[j+2] = base64[(int)sixtet];
		sixtet = x[i+2] & 0b00111111;
		y[j+3] = base64[(int)sixtet];
		
	}
	fwrite(y, sizeof(char), j , stdout);
	return 0;
}
