#include <stdio.h>


main() 
{
	float celsius, fahr;
	int lower, upper, step;
	char *c_head, *f_head;

	lower = 0;
	upper = 300;
	step = 20;
	c_head = "Celcius";
	f_head = "Fahrenheit";

	printf("%10s %10s\n", c_head, f_head);

	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * 9.0/5.0 + 32.0;
		printf("%10.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
