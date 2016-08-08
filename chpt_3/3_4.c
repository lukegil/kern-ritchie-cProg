#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void itoa(int n, char s[11]);

int main() {
	char s[11];
	int i = INT_MIN;
	int j = INT_MAX;
	printf("divide : %d\n", i );
	printf("divide : %d\n", j );
	itoa(i, s);
	printf("%s\n",s);
	for (int j = 11; j >= 0; j--)
		putchar(s[j]);
	printf("\n");
	
}

void itoa(int n, char s[]) {
	int i, sign;
	
	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
		printf("loop %d\n", s[i]);
	} while (n/=10);
	if (sign < 0)
		s[i++] = '-';

}
