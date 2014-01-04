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

#include <ctype.h>


int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t'){;}
	
	s[1] = '\0';
	if(!isdigit(c) && c != '.'){
		return c;
	}
	i = 0;
	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch())){;}
	}
	if(c == '.'){
		while(isdigit(s[++i]= c= getch())){;}
	}	
	s[i] = '\0';
	if(c != EOF){
		ungetch(c);
	}
	return NUMBER;
	 
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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
	return (bufp > 0)? buf[--bufp]: getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE){
		printf("ungetch: too many characters!\n");
	}
	else{
		buf[bufp++] = c;
	}
}
