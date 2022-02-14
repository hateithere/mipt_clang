#include <stdio.h>

int main() {
	FILE *input = fopen("input.txt","r");
	unsigned long long int nya;
	fscanf(input, "%lld\n", &nya);
	fclose(input);
	FILE *output = fopen("output.txt","w");
	fprintf(output, "%llo", nya);
	fclose(output);
	return 0;
}

