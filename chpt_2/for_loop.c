#include <stdio.h>

int main() {
	int lim = 20;
	char s[lim];
	int c;

	for (int i = 0; (i < lim - 1) == ((c = getchar()) != '\n') == (c != EOF); ++i ) {
		printf("%c\n", c);
		s[i] = c;
	}
	printf("%s\n", s);

	return 0;
}
