#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printmem(void* start_address);

struct chamber {
	char name[15];
	int pressure;
};

int main(void) {
	struct chamber chamber1;
	strcpy(chamber1.name, "alpha");
	chamber1.pressure = 0xAB;
	printmem(&chamber1);
	printf("Enter new name for chamber:\n");
	scanf("%s",chamber1.name);
	printmem(&chamber1);
	return 0;
}

void printmem(void* address) {
	const unsigned int WINDOW = 30;
	unsigned char* p = (unsigned char *)(address);
	for (p -= WINDOW; p < (unsigned char *)(address + WINDOW); ++p) {
		printf("%p: %02X (%c)\n", p, (unsigned int)*p, *p);
	}
}
