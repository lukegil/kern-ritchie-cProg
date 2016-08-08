#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);


/* reverse polish calculator
   
   Max size supported is double.

   1. read in a line
   2. push numbers to a stack
   3. when an operator is found, pop from stack and run operation
   4. push the result back to the top of the stack
*/

int main() {
	int type;
	double op2;
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
			//add raise error
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error : unknown command %s\n", s);
			// add raise error
			break;
		}
	}
	return 0;				
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
	//add error handling
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
		return 0.0;
	}
}   

