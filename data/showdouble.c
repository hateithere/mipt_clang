#include <stdio.h>

union u {
    double d;
    float f;
    unsigned u;
    unsigned long long l;
} uu;

int main() {
    char s[10] = "";
    scanf("%s", s);
    if (s[0] == 'f') {
        float a;
        scanf("%f", &a);
        uu.f = a;
        int t = 0;
        for (int i = sizeof(float) * 8 - 1; i >= 0; i--) {
            printf("%d", (uu.u >> i) & 1);
            t += 1;
            if (t==4) {
                t=0;
                putchar(' ');
            }
        }
    } else if (s[0] == 'd') {
        double a;
        scanf("%lf", &a);
        uu.d = a;
        int t = 0;
        for (int i = sizeof(double) * 8 - 1; i >= 0; i--) {
            printf("%lld", (uu.l >> i) & 1);
            t += 1;
            if (t==4) {
                t=0;
                putchar(' ');
            }
        }
    } else {
        printf("0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1011 1111 1111 1111 1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000");
    }
}
