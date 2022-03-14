#include <stdio.h>
#include <math.h>
#define THR 32
#define MEM 128
#define REG 2
#define MAXTHR 1536
#define MAXMEM 49152
#define MAXREG 32768


int check_use(int x, const int frac);

int main() {
	int reg, thr, mem;
	int nbreg, nbmem, nbthr;
	int nthr;
	int min = 0;

	freopen("cuda.in", "r", stdin);
#ifndef _DEBUG
	freopen("cuda.out", "w", stdout);
#endif
	scanf("%d %d %d", &thr, &reg, &mem);

	nthr = check_use(thr, THR);
	nbthr = (int) MAXTHR / nthr;	
	nbreg = (int) MAXREG / (nthr*check_use(reg, REG));
	nbmem = (int) MAXMEM / check_use(mem, MEM);
	

	if ((nbthr <= nbreg) && (nbthr <= nbmem))
		min = nbthr;
	else if ((nbreg <= nbthr) && (nbreg <= nbmem))
		min = nbreg;
	else if ((nbmem <= nbthr) && (nbmem <= nbreg))
		min = nbmem;
#ifdef _DEBUG
	printf("used: %d %d %d\n", check_use(thr, THR), nthr*check_use(reg, REG), check_use(mem, MEM));
	printf("By threads: %d, by registers: %d, by memory: %d\n", nbthr, nbreg, nbmem);
#endif
	printf("%d", (int)round((thr*min*100)/(double)MAXTHR));
	return 0;
}

int check_use(int x, const int frac) {
	int real_x = frac;
	while (1) {
		real_x += frac;
		if (real_x >= x) {
			x = real_x;
			break;
		}
	}
#ifdef _DEBUG
	printf("%d %d\n", x, real_x);
#endif
	return x;
}
