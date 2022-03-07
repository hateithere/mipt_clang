#include <stdio.h>
#include <stdint.h>
//#define _DEBUG
int check_registers(int a, int b, int max_reg);
int main() {
	int max_reg = 4;
#ifdef REGISTERS
	max_reg = REGISTERS;
#endif
	/* A, B, C, D. Indice + 5 */
	uint8_t reg[4] = {0, 0, 0, 0};
	int i;
	uint8_t a, b;
	uint8_t x;

#ifdef _DEBUG
	printf("%hhu\n", x);
#endif
	
	while (1) {
		x = getchar() - '0';
#ifdef _DEBUG
		printf("x:%hhu\n", x);
#endif
		switch (x) {
			case 0:
				return 0;
				break;
			case 1:
				scanf("%hhu %hhu\n", &a, &b);
				if (check_registers(a, b, max_reg)) {
					printf("-1\n");
					return 0;
				}
				reg[a-5] += reg[b-5];
				break;
			case 2:
				scanf("%hhu %hhu\n", &a, &b);
				if(check_registers(a, b, max_reg)) {
					printf("-1\n");
					return 0;
				}
				reg[a-5] -= reg[b-5];
				break;
			case 3:
				scanf("%hhu %hhu\n", &a, &b);
				if(check_registers(a, 0, max_reg)) {
					printf("-1\n");
					return 0;
				}
				reg[a-5] = b;
				break;
			case 4:
				for (i = 0; i < max_reg; ++i)
					printf("%hhu ", reg[i]);
				putchar('\n');
				break;
		}
	}
}

int check_registers(int a, int b, int max_reg) {
	a -= 5;
	b -= 5;
	if ((a >= max_reg) || (b >= max_reg))
		return 1;
	return 0;
}
