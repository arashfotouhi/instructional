#include <stdio.h>
#include <stdlib.h>

void printmem(void* start_address);

int main(void) {
	char pass[10] = "password";
	char name[16] = "noname";
	printmem(name);
	printf("Hi, What is your name?\n");
	scanf("%s",name);
	printf("Hi %s\n", name);
	printf("Password is: %s\n", pass);
	printmem(name);
	return 0;
}

void printmem(void* address) {
	const unsigned int WINDOW = 20;
	char* p = (char *)(address);
	for (p -= WINDOW; p < (char *)(address + WINDOW); ++p) {
		printf("0x%08X: %c\n", p, *p);
	}
}
