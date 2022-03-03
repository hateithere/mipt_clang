#include <stdio.h>

const char* gender[] = {"fe", "ma"};
const char* intel[] = {"du", "cl"};
const char* hat[] = {"nh", "ha"};
const char* legs[] = {"sk", "tr"};
const char* hair[] = {"bn", "rd", "bw", "bk"};
const char* eyes[] = {"bu", "ge", "gy", "da"};

void print_feature(int x, const char* features[], int bit, int len);

int main() {
	int nya;

	scanf("%x", &nya);
	
	print_feature(nya, gender, 0, 1);
	print_feature(nya, intel, 1, 1);
	print_feature(nya, hat, 2, 1);
	print_feature(nya, legs, 3, 1);
	print_feature(nya, hair, 4, 2);
	print_feature(nya, eyes, 6, 2);
	return 0;
}

void print_feature(int x, const char* features[], int bit, int len) {
	int t;
	if (len == 1) {
		t = (x >> bit) & 1;
	}
	else {
		t = (x >> bit) & 1;
		t += ((x >> (bit + 1)) & 1) * 2;
	}
	printf("%s ", features[t]);
}

