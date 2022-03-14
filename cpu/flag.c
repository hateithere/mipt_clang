#include <stdio.h>
#include <stdint.h>

int check_registers(int a, int b, int max_reg);
int main() {
	int max_reg = 4;
	int zf = 0, to_exec = 1;
#ifdef REGISTERS
	max_reg = REGISTERS;
#endif
	/* A, B, C, D. Indice - 5 */
	uint8_t reg[4] = {0, 0, 0, 0};
	int i;
	uint8_t a, b;
	uint8_t x;
	
	while (1) {;
		scanf("%hhu", &x);
#ifdef _DEBUG
		printf("x:%hhu\n", x);
#endif
		if ((x & (1 << 7)) && !zf) {
			to_exec = 0;
			//zf = 0;
		}
		x &= 0x7F;
#ifdef _DEBUG
		printf("zf:%d, to_exec:%d\n", zf, to_exec);
#endif
		if (to_exec == 0) {
			if ((x >= 1) && (x <= 3))
				scanf("%hhu %hhu\n", &a, &b);
			to_exec = 1;
			zf = 0;
			continue;
		}

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
				if (reg[a-5] == 0)
					zf = 1;
				else
					zf = 0;
				break;
			case 2:
				scanf("%hhu %hhu\n", &a, &b);
				if(check_registers(a, b, max_reg)) {
					printf("-1\n");
					return 0;
				}
				reg[a-5] -= reg[b-5];
				if (reg[a-5] == 0)
					zf = 1;
				else
					zf = 0;
				break;
			case 3:
				scanf("%hhu %hhu\n", &a, &b);
				if(check_registers(a, 0, max_reg)) {
					printf("-1\n");
					return 0;
				}
				reg[a-5] = b;
				if (reg[a-5] == 0)
					zf = 1;
				else
					zf = 0;
				break;
			case 4:
				for (i = 0; i < max_reg; ++i)
					printf("%hhu ", reg[i]);
				putchar('\n');
				break;
		}
		to_exec = 1;
	}
}

int check_registers(int a, int b, int max_reg) {
	a -= 5;
	b -= 5;
	if ((a >= max_reg) || (b >= max_reg))
		return 1;
	return 0;
}
