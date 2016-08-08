#include <stdio.h>
#define LIM 10
int main() {
	int c;
	int word1[LIM], word2[LIM];
	int word1_lim, word2_lim;
	int hit_space=0; // whether we've reached the seperator
	printf("enter space sep words\n");
	
	for (int i = 0; i < LIM && (c = getchar()) != '\n'; ++i) {
		
		if (c == ' ') {
			hit_comma = 1;
			word1_lim = i;
			continue;
		}

		if (!hit_comma) 
			word1[i] = c;
		else if (hit_comma)
			word2[i] = c;
		else
			return 0;
		word2_lim = 0;
	}
	for (int j = 0; j < LIM; ++j) {
		putchar(word1[j]);
	}

}
