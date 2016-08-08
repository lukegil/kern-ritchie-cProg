#include <stdio.h>
#define MAXLENGTH 1000

int get_line(char word[MAXLENGTH], int maxlength, int test); 

/* print lines and their length */

main() 
{
	char word[MAXLENGTH], cur_char;
	int length, test;

	test = 7;
	length = get_line(word, MAXLENGTH, test);
	if (length > 80) {
			printf("%d | %s\n", length, word);	
	}
}

int get_line(char word[MAXLENGTH], int maxlength, int test) {
	char cur_char;
	int length;

	++test;
	while ((cur_char = getchar()) && 
		   length < MAXLENGTH && 
		   cur_char != '\t' && 
		   cur_char != '\n') {
		
		if (cur_char > 32) {
			word[length] = cur_char;
			++length;
		}
	}

	return length;
}
