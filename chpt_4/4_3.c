/* Exercises 4-3 through 4-10 ; Page 79

   4-3 : Given the basic framework, add the modulus operator 
   		 and provisions for negative numbers

   4-4 : Add commands to 
         - print the top element of the stack without popping
         - duplicate the top element (without popping)
         - swap the top two elements
		 - clear the stack

*/


#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double modulus(double main_num, double bound);


/* reverse polish calculator
   
   Max size supported is double.

   1. read in a line
   2. push numbers to a stack
   3. when an operator is found, pop from stack and run operation
   4. push the result back to the top of the stack
*/

int main() {
	int type;
	double op2, op3;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		/* communicative ops */
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		
		 /* non communicative ops */
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error : zero divisor\n");
			//LG TODO : add raise error
			break;
		case '%':
			op2 = pop();
			push( modulus(pop(), op2));
			break;
		case 'D':
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 'S':
			op2 = pop();
			op3 = pop();
			push(op2);
			push(op3);
			break;
		/* Printing and formatting */
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case 'P':
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		default:
			printf("error : unknown command %s\n", s);
			// LG TODO : add raise error
			break;
		}
	}
	return 0;				
}

/* modulus() : Performs modulus on double, as opposed to only ints

   @param : dividend - the first number in the equation
   @param : divisor - The second number in the equation
   @return : the answer
   
   1. subtract until you hit less than 0
   2. print the number from the iteration before
    
*/
double modulus(double main_num, double bound) {
	double prev_num;
	
	if (main_num < 0.0)
		main_num *= -1.0;

	if (bound < 0.0) 
		printf("divisor must be > 0");
	//LG TODO : allow for divisors of any sign

	while (main_num >= 0.0){
		prev_num = main_num;
		main_num -= bound;
	}
	return prev_num;
	
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack
   
   @param : a double to push onto the stack
   @return : void

   @external : sp - keeps track of stack
   @external : val - the stack of numbers

*/

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error : stack full, can't push %g\n", f);
	//LG TODO : add error handling
}


/* pop : pop and return top value from stack 

   @param : none
   @return : double that was popped from stack

   @external : sp - keeps track of stack
   @external : val - the stack of numbers
*/
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error : stack empty\n");
		//LG TODO : Add error 
		return 0.0;
	}
}   


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop : get the next operator or numeric operand 

   @param : s[] - array of input characters
   @return : integer of the ascii character value. So, + returns 43

   1. skip all spaces
   2. if you hit a non-digit && non-decimal, return it
   3. if a '-', check if negative number, else return
   5. read in a number. 
   6. Push the final char (that's not the number) to the ungetch()/getch() stack

*/

int getop(char s[]) {
	int i; //indx of s
	int c; //current char

	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* not a number */

	i = 0;

	if (c == '-')  {
		if (!isdigit(c = getch())) {
			ungetch(c);
			return '-';
		} 
		s[i++] = '-';
		s[i] = c;
	}

	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()));

	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* getch() : get the next character
   
   @param : void
   @return : int - the next character

   @global : buf - the buffer used to save characters
   @global : bufp - the next indx in buf

   1. return either the next char from buf or the next from stdin
*/

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch() : save a character in the buffer

   @param : int of ascii character to save
   @return : void

   @global : buf - the buffer used to save characters
   @global : bufp - the next indx in buf
  
   1. If there's space in the buffer add the char and increase indx

*/

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch : too many characters\n");
	//LG TODO : add error handling
	else 
		buf[bufp++] = c;
}
