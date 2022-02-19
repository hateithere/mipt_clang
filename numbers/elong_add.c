#include <stdio.h>
#include <stdlib.h>
#define N 100

struct _Decimal {
	char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
	unsigned int n;
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};

Decimal add(Decimal a, Decimal b) {
	Decimal c;
	char cf = 0;
	unsigned int i;

	if (a.n < b.n) {
		c = a;
		a = b;
		b = c;
	}
	c.n = a.n;
	
	for (i = 0; i <= b.n; ++i) {
		c.a[i] = (a.a[i] + b.a[i] + cf) % 10;
		cf = (int)((a.a[i] + b.a[i] + cf) / 10);
	}
	
	for (; i <= a.n; ++i) {
		c.a[i] = (a.a[i] + cf) % 10;
		cf = (int)((a.a[i] + cf) / 10);
	}
	if (cf) {
		++c.n;
		c.a[i] = cf;
	}
	return c;
	
}

void print(Decimal x) {
	for (int i = x.n; i >= 0; --i)
		printf("%d", x.a[i]);
	printf("\n");
}

int main(){
    Decimal b = {{9, 9, 9}, 2};
    Decimal a = {{2}, 0};

    Decimal res;
    
    res = add(a, b);
    print(res);  
    return 0;
}
