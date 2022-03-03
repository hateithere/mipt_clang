#include <stdio.h>

int main() {
	FILE *input = fopen("bit_3.dat","r");
	int nya;
	char t;
	fscanf(input, "%x\n", &nya);
	fclose(input);

	t = (nya >> 4) & 1;
	t += ((nya >> 5) & 1) * 2;
	
	FILE *output = fopen("bit_3.ans","w");
	switch (t) {
		case 3:
			fprintf(output, "%s", "bk");
			break;
		case 2:
			fprintf(output, "%s", "bw");
			break;
		case 1:
			fprintf(output, "%s", "rd");
			break;
		case 0:
			fprintf(output, "%s", "bn");
			break;
	}
	
	fclose(output);
}
