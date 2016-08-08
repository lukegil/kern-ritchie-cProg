#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
	float fahr;
	char *c_head, *f_head;


	c_head = "Celcius";
	f_head = "Fahrenheit";

	printf("%10s %10s\n", f_head, c_head);

	for (fahr=UPPER; fahr >= LOWER; fahr = fahr - STEP) {
		printf("%10.0f %10.1f\n", fahr,(5.0/9.0) * (fahr - 32.0));
	}
}
