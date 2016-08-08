#include <stdio.h>
#include <math.h>
#define LIM 10
int main() {
	int c; //input char
	int j, k; // loop indxs
	int interm;
	char string[LIM];
	int final_num = 0;

	j = k = 0;
	while (j < LIM && (c = getchar()) != '\n') {
		if (c == 'x' || c == 'X') {
			j = 0;
			continue;
		}

		if ('0' <= c && c <= '9') 
			string[j] = c - '0';
		else if ('A' <= c && c <= 'F' ) 
			string[j] = c - 'A' + 10;
		else if ('a' <= c && c <= 'f' )
			string[j] = c - 'a' + 10;
		else 
			return 0;
		++j;
	}
		
	final_num = 0;
	j = j - 1; // because of ++j at end of loop
	for (; k <= j; ++k) {
		interm = pow(16, j - k);
		final_num += (interm * string[k]);
				
	}
	printf("%d\n", final_num);

}
