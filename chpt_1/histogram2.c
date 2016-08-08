#include <stdio.h>

int highest,i, j, c, letters[58];

main() {
	highest = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		if (c < 'A' || c > 'z') 
			continue;

		++letters[c - 'A'];
	}
		for (i = 0; i < 58; ++i) {
			putchar(i + 'A');
			printf(" | ");
			for (j = 0; j < letters[i]; ++j) {
				printf("[]");
			}
		printf("\n");
		
	}
	
}
