#include <stdint.h>
#include <stdio.h>
typedef uint8_t byte;
typedef uint16_t word;
typedef uint16_t adr;

byte mem[1 << 16];

byte b_read (adr a) {
	return mem[a];
}
void b_write (adr a, byte val) {
	mem[a] = val;
}
word w_read  (adr a) {
	return *(word*)&mem[a];
}
void w_write (adr a, word val) {
	*(word*)&mem[a] = val;
}
void load_file() {
	adr a;
	int n, i;
	byte x;

	while(scanf("%hx %x", &a, &n) != EOF) {
		//printf("%x", n);
		for (i = 0; i < n; ++i) {
			//printf("number %d\n", i);
			scanf("%hhx", &x);
			b_write(a+i, x);
			//printf("Read %hx\n", mem[a+2*i]);
		}
	}
}

void mem_dump(adr start, word n) {
	for (int i = 0; i < n; i+=2) {
		//printf("%d:read from %hx: %hx\n", i,start+i, *(word*)&mem[start+i]);
		printf("%06ho : %06ho\n", start+i, *(word*)&mem[start+i]);
	}
}
//int main() {
//	load_file();
//	mem_dump(0x40, 4);
//}
