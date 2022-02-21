#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

	char x = 0;
	if (argc)
		x =  strtoq(argv[1], NULL, 16);

	if (x & 1)
		printf("ma\n");
	else
		printf("fe\n");
	return 0;
}
