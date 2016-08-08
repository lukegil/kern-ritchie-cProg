#include <stdio.h>

#define MAXLINE 20

int strrindex_last(char line[], char pattern[]);

int main() {
	char line[] = "Hhhello how are hello I said";
	char pattern[] = "ello";

	printf("index : %d\n", strrindex_last(line, pattern));

}

/* return the last index of pattern in line */
int strrindex_last(char line[], char pattern[]) {
	int i, j, k;
	int last_indx = -1;
	//For each character of line[], until you reach a null char
	for (i = 0; line[i] != '\0'; i++) {
		/* Starting at the beginning of the pattern (pattern[k]) and
		   at the nth character of line[], if you reach a 
		   null char (EOL) or a letter in line that doesn't match 
		   a letter in pattern, break out of the loop */
		for (j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
			;
		
		/* if we've made it to the end of the pattern (and a pattern
		   that's not just "\0", return the index of line. */
		if (k > 0 && pattern[k] == '\0')
			last_indx =  i;
	}
	
	return last_indx;
}
