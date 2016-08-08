#include <stdio.h>


int main() {
	unsigned int c;
	//A-Z 65 - 90
	//a-z 97 - 122

	while ((c = getchar()) != '\n') {
		(c <= 90) ? putchar(c + 32) : putchar(c);
	}
	printf("\n");
	return 0;
}
