#include <stdio.h>

int main() {
	unsigned int ip[4];
	unsigned int netmask[4];
	unsigned int broadcast[4] = {0, 0, 0, 0};
	int i;

	scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
	scanf("%d.%d.%d.%d", &netmask[0], &netmask[1], &netmask[2], &netmask[3]);
	for (i = 0; i < 4; ++i) {
		broadcast[i] = (ip[i] & netmask[i]) | (~netmask[i] & 255);
	}
	for (i = 0; i < 3; ++i)
		printf("%d.", broadcast[i]);
	printf("%d", broadcast[3]);
}
