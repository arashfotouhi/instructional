#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct chamber {
	char name[15];
	int pressure;
};

void printmem(void* start_address);
void printmem_int(void* start_address);
int is_chamber_safe(const struct chamber *);
void check_chamber(const struct chamber *);

int main(void) {
	struct chamber chamber1;
	strcpy(chamber1.name, "alpha");
	chamber1.pressure = 0xBB;
	printmem(&chamber1);
	printf("Chamber pressure: %X\n", chamber1.pressure);
	check_chamber(&chamber1);
	printf("Enter new name for chamber:\n");
	scanf("%s",chamber1.name);
	printmem(&chamber1);
	printf("Chamber pressure: %X\n", chamber1.pressure);
	check_chamber(&chamber1);
	printmem_int(&chamber1);
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

void printmem_int(void* address) {
	const unsigned int WINDOW = 20;
	unsigned int* p = (unsigned int *)(address);
	printf("--------------------------------\n");
	for (p; p < (unsigned int *)(address + WINDOW); ++p) {
		printf("%p: 0x%08X\n", p, *p);
	}
	printf("--------------------------------\n");
}

int is_chamber_safe(const struct chamber *ch) {
	const int SAFE_LEVEL = 0x44;
	if (ch->pressure < SAFE_LEVEL) {
		return 1;
	}
	else {
		return 0;
	}
}

void check_chamber(const struct chamber *ch) {
	if (is_chamber_safe(ch)) {
		printf("Chamber is safe.\n");
	}
	else {
		printf("CHAMBER PRESSURE TOO HIGH!!!!\n");
	}
}
