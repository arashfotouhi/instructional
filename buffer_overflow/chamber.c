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
	chamber1.pressure = 0xBB;
	printmem(&chamber1);
	printf("Chamber pressure: %X\n", chamber1.pressure);
	printf("Enter new name for chamber:\n");
	scanf("%s",chamber1.name);
	printmem(&chamber1);
	printf("Chamber pressure: %X\n", chamber1.pressure);
	return 0;
}

void printmem(void* address) {
	const unsigned int WINDOW = 20;
	unsigned char* p = (unsigned char *)(address);
	printf("--------------------------------\n");
	for (p; p < (unsigned char *)(address + WINDOW); ++p) {
		printf("%p: %02X (%c)\n", p, (unsigned int)*p, *p);
	}
	printf("--------------------------------\n");
}
