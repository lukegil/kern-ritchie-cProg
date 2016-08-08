#include <stdio.h>

/* Write the function itob(n,s,b) that converts the integer n 
   into a base `b` character representation in the string s. 
   In particular, itob(n,s,b) formats n as a hexadecimal int in s */

#define ARR 10
#define NUM 34
#define BSE 2

void itob(int number, char string[], int base);
int num_to_char(int num) ;

int main(void) {
	int arr_length = ARR;
	char string[arr_length];
	int number = NUM;
	int base = BSE;

	itob(number, string, base);
	
	printf("\n %s \n ", string);
	

}


void itob(int number, char string[], int base) {
	int arr_length = ARR;
	int ascii_nums[arr_length];
	for (int k = 0; k < arr_length; ++k) 
		ascii_nums[k] = 0;

	do {
		for (int i = arr_length - 1; i >= 0; --i) {
			//if value can be added without wrapping, break
			ascii_nums[i] = ++ascii_nums[i] % base;
			if (ascii_nums[i] != 0)
				break;			
		}
	} while ((number -= 1) > 0);
	
	for (int j = arr_length - 1; j >= 0; --j) {
	
		string[j] = num_to_char(ascii_nums[j]);
	}
}

int num_to_char(int num) {
	if (num <= 9)
		return num + '0';
	else 
		return num - 10 + 'A';
}
