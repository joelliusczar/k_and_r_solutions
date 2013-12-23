#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

main(void)
{
	int type;
	double op1,op2,fracPart;
	char s[MAXOP];
	
	
	while((type = getop(s))!= EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0){
					push(pop() / op2);
				}
				else{
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				op1 = pop();
				fracPart = (op1 - ((int)op1)) + (op2 - ((int)op2));
				if(fracPart != 0.0){
					printf("Integer-only operation on floating point number.\n");
					break;
				}
				if(op2 != 0.0){
					push((int)(op1) % ((int)op2));
				}
				else{
					printf("error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error: unkown command %s\n",s);
				break;
		}
	
	}
	return 0;
}
