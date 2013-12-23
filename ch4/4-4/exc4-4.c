#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

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
