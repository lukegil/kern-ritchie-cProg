#include <stdio.h>

int c, where, length, i;
int word[100];

#define IN 1
#define OUT 0


main() 
{
	where = IN;
	while ((c = getchar()) != EOF) {
		// If word is done
		if (where == IN && (c == ' ' || c == '\t' || c == '\n')) {
			where = OUT;
			printf("length : %3d | ", length);
			for (i = 0; i <= length; ++i) {
				if (word[i] != 0) {
					putchar(word[i]);
					word[i] = 0;
				}
			}

			length = 0;
			printf("\n");
		//if a letter 

		} else if ( c != ' ' && c != '\t' && c != '\n' ) {
			where = IN;
			++length;
			word[length] = c;
		// if it's a dupe non-char
		} else {
			;
		}
	}
	printf("\n");
}
