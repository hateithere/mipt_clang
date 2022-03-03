#include <stdio.h>
#include <string.h>
const char* gender[] = {"fe", "ma"};
const char* intel[] = {"du", "cl"};
const char* hat[] = {"nh", "ha"};
const char* legs[] = {"sk", "tr"};
const char* hair[] = {"bn", "rd", "bw", "bk"};
const char* eyes[] = {"bu", "ge", "gy", "da"};

void add_feature(int *res, int val, int len, int pos);
int check_in(char *src, const char* feature[], int l);

int main() {
	char x[1000] = "";
	char buf[3] = "";
	int res = 0;
	int len, i, pos;
	
	scanf("%[^\n]", x);
	len = (int)strlen(x);

	for (i = 0; i < len; i += 3) {
		buf[0] = x[i];
		buf[1] = x[i+1];
		buf[2] = '\0';
		
		if ((pos =  check_in(buf, gender, 2)) != -1) {
			add_feature(&res, pos, 1, 0);
		}
		if ((pos =  check_in(buf, intel, 2)) != -1) {
			add_feature(&res, pos, 1, 1);
		}
		if ((pos =  check_in(buf, hat, 2)) != -1) {
			add_feature(&res, pos, 1, 2);
		}
		if ((pos =  check_in(buf, legs, 2)) != -1) {
			add_feature(&res, pos, 1, 3);
		}
		if ((pos =  check_in(buf, hair, 4)) != -1) {
			add_feature(&res, pos, 2, 4);
		}
		if ((pos =  check_in(buf, eyes, 4)) != -1) {
			add_feature(&res, pos, 2, 6);
		}
	}
	printf("%x", res);
}

void add_feature(int *res, int val, int len, int pos) {
	int mask;
	if (len == 1) {
		mask = 1 << pos;
		*res = ((*res & ~mask) | (val << pos));
	}
	else {
		mask = 1 << pos;
		*res = ((*res & ~mask) | ((val % 2)<< pos));
		mask = 1 << (pos + 1);
		*res = ((*res & ~mask) | ((int)(val / 2)<< (pos + 1)));
	}
}

int check_in(char *src, const char* feature[], int l) {
	int i;
	for (i = 0; i < l; ++i) {
		if (!strcmp(feature[i], src)) {
			return i;	
		}
	}
	
	return -1;
}
