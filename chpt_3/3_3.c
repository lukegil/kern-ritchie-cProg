#include <stdio.h>
void expand(int s1[1000], int s2[1000]);

int main() {
	int s1[1000], s2[1000], c;
	int i = 0;
	while ((c = getchar()) != '\n') {
		s1[i] = c;
		++i;
	}
	printf("\n");
	for (i = 0; i < 1000 & s1[i] != '\0'; ++i)
		putchar(s1[i]);
	printf("\n");

	s1[i] = '\0';
	expand(s1, s2);
	for (i = 0; i < 1000 & s2[i] != '\0'; ++i)
		putchar(s2[i]);
	printf("\n");
}

void expand(int s1[1000], int s2[1000]) {
	int i, j, k;
	i = j = 0;
	while (s1[i] != '\0') {

		if (s1[i] == '-') {
			
			if ((i - 1) == -1 || s1[i + 1] == '\0') {
				s2[j] = '-';
				++j, ++i;
				continue;
			}
			
			for (k = s1[i - 1] + 1; k < s1[i + 1]; ++k) {
				s2[j] = k;
				++j;
			}
		} else {
			s2[j] = s1[i];
			++j;
		}
		++i;
	}
	s2[j] = '\0';
}
