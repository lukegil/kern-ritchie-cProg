#include <stdio.h>

/* prints a conversion table for 
   fahrenheit to celcius */


int convert(int fahr);

main() 
{
	float fahr, celcius;
	int lower, upper, step;
	char *celc_head, *fahr_head;
	lower = 0; //Lower limit of temp table
	upper = 300; //upper limit of temp table
	step = 20; //run for every 20th degree

	fahr = lower;

	/* the headers */
	celc_head = "Celcius";
	fahr_head = "Fahrenheit";
	printf("%10s %10s\n",fahr_head, celc_head);
	while (fahr <= upper) {
		celcius = convert(fahr);
		printf("%10.0f %10.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
}

//returns celcius
int convert(int fahr) {
	int celc;
	celc = (5.0/9.0) * (fahr - 32);
	return celc;
}
