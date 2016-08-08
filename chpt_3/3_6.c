#include <stdio.h>

#define NUM 8340110
#define LEN 15

void itoa(int number, char string[], int length);

int main() {
	int length = LEN;
	char string[length];
	int number = NUM;
	
	itoa(number, string, length);
	printf("\n %s \n", string);
}


void itoa(int number, char string[], int length) {
	int j = length - 1;

	do {
		string[j] = number % 10 + '0';
	} while (--j && (number /= 10) > 0);

	for (; j >= 0; --j) 
		string[j] = '_';
		
}
