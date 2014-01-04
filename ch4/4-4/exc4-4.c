/*expected output*/

/*36*/
/*36*/
/*36*/
/*17*/
/*18*/
/*17*/
/*error: stack empty*/
/*0*/
/*error: stack empty*/
/*0*/
/*error: insufficient number of elements in stack.*/


#include <stdio.h>
#include <stdlib.h>

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void switchtoptwo(void);
void clearstack(void);

main(void)
{
	push(5);
	push(1);
	push(14);
	push(22);
	push(45);
	push(18);
	push(17);
	push(36);
	
	printf("%g\n",peek());
	printf("%g\n",peek());
	printf("%g\n",pop());
	printf("%g\n",peek());
	switchtoptwo();
	printf("%g\n",peek());
	switchtoptwo();
	printf("%g\n",peek());
	clearstack();
	printf("%g\n",peek());
	printf("%g\n",pop());
	switchtoptwo();
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL){
		val[sp++] = f;
	}
	else{
		printf("error: stack full, can't push %g\n",f);
	}
}

double pop()
{
	if(sp > 0){
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
	
}

double peek()
{
	if(sp > 0){
		return val[sp-1];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void switchtoptwo()
{
	double temp;
	if(sp > 1){
		temp = val[sp -1];
		val[sp -1] = val[sp -2];
		val[sp -2] = temp;
	}
	else{
		printf("error: insufficient number of elements in stack. \n");
	}
}


void clearstack()
{
	sp = 0;
}
