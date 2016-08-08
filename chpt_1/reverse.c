#include <stdio.h>
#define MAXLENGTH 10

void reverse( char word[MAXLENGTH], char reverse_word[MAXLENGTH], int word_length );
int get_word(char word[MAXLENGTH]);

main() {
	char word[MAXLENGTH], reverse_word[MAXLENGTH];
	int indx, length;

	length = get_word(word);
	reverse(word, reverse_word, length);
	printf("%s\n", reverse_word);
}


void reverse( char word[MAXLENGTH], char reverse_word[MAXLENGTH], int word_length ) {
	int word_indx, indx;
	
	word_indx = -1;
	for (indx = word_length - 1; indx >= 0; --indx ){ 
	
		if (word_indx == -1 && 65 < word[indx] && word[indx] < 122) {
			word_indx = 0;
		}	

		if (word_indx >= 0) {
			reverse_word[word_indx] = word[indx];
			++word_indx;
		}
	}
}

int get_word( char word[MAXLENGTH] ) {
	int cur_char, indx;
	indx = 0;
	while ((cur_char = getchar()) != EOF && cur_char != '\n') {
		word[indx] = cur_char;
		++indx;
	}
	return indx;
}
