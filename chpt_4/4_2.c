#include <stdio.h>
#include <ctype.h>

int main() {
	double atof(char string[]);

	printf("result : %f\n", atof("123.45e-6"));

}

double atof(char string[]) {
	void string_to_double(char string[], double ret_vals[], int i);
	double val, power, ret_vals[2];
	int i, j, sign, exponent, exp_2;
	short sn_sign;

	/* skip leading whitespaces */
	for (i = 0; isspace(string[i]); i++) 
		;

	//If there is a '-', it is a negative number
	sign = (string[i] == '-') ? -1 : 1;
	
	//If there is a sign, skip this character
	if (string[i] == '+' || string[i] == '-')
		i++;
	
	string_to_double(string, ret_vals, i);
	val = ret_vals[0];
	i = (int) ret_vals[1];

	if (string[i] == '.')
		i++;
	
	for (power = 1.0; isdigit(string[i]); i++) {
		val = 10.0 * val + (string[i] - '0');
		power *= 10.0;
	}

	if (string[i] == 'e')
		i++;
	if (string[i] == '-') {
		sn_sign = -1;
		i++;
	} else if (string[i] == '+') {
		sn_sign = 1;
		i++;
	} else {
		sn_sign = 1;
	}
	
	string_to_double(string, ret_vals, i);
	exponent = (int) ret_vals[0];
	
	for (exp_2 = 1, j = 0; j < exponent; j++)
		exp_2 *= 10;
	
	val =  sign * val / power;
	
	if (sn_sign == 1)
		return val * exp_2;
	else
		return val / exp_2;

}

void string_to_double(char string[], double ret_vals[], int i) {
	double val;
	//add every digit to val * 10 
	for (val = 0.0; isdigit(string[i]); i++)
		val = 10.0 * val + (string[i] - '0');
	ret_vals[0] = val;
	ret_vals[1] = i;
}
