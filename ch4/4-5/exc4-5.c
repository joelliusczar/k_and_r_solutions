#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION 'f'


int getop(char []);
void push(double);
double pop(void);
double mathfunctions(char[]);

main(void)
{
	int type;
	double op2;
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
			case FUNCTION:
				push(mathfunctions(s));
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
	
	i = 0;
	if(isalpha(c)){
		while(isalpha(s[++i] = c = getch())){;}
		s[i] = '\0';
		if(c != EOF){
			ungetch(c);
		}
		return FUNCTION;
	}
	
	
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

#include <math.h>
#include <string.h>

double mathfunctions(char s[])
{
	double pop(void);
	double op1,op2;
	op1 = op2 = 0;
	if(strcmp(s,"sin")== 0){
		return sin(pop());
	}
	else if(strcmp(s,"cos")==0){
		return cos(pop());
	}
	else if(strcmp(s,"tan")==0){
		return tan(pop());
	}
	else if(strcmp(s,"asin")==0){
		op1 = pop();
		if(op1 <= 1.0 && op1 >= -1.0){
			return asin(op1);
		}
		else{
			printf("Input outside of function range");
			return 0.0;
		}
	}
	else if(strcmp(s,"acos")==0){
		op1 = pop();
		if(op1 <= 1.0 && op1 >= -1.0){
			return acos(op1);
		}
		else{
			printf("Input outside of function range");
		}
	}
	else if(strcmp(s,"atan")==0){
		return atan(pop());
	}
	else if(strcmp(s,"sinh")==0){
		return sinh(pop());
	}
	else if(strcmp(s,"cosh")==0){
		return cosh(pop());
	}
	else if(strcmp(s,"tanh")==0){
		return tanh(pop());
	}
	else if(strcmp(s,"exp")==0){
		return exp(pop());
	}
	else if(strcmp(s,"log")==0){
		op1 = pop();
		if(op1 >0){
			return log(op1);
		}
		else{
			printf("Input must be greater than zero");
			return 0.0;
		}
	}
	else if(strcmp(s,"log10")==0){
		op1 = pop();
		if(op1 >0){
			return log10(op1);
		}
		else{
			printf("Input must be greater than zero");
			return 0.0;
		}

	}
	else if(strcmp(s,"sqrt")==0){
		op1 = pop();
		if(op1 >=0){
			return sqrt(op1);
		}
		else{
			printf("Input must be equal or greater than zero");
			return 0.0;
		}

	}
	else if(strcmp(s,"ceil")==0){
		return ceil(op1);
	}
	else if(strcmp(s,"floor")==0){
		return floor(op1);
	}
	else if(strcmp(s,"pow")==0){
		op1 = pop();
		op2 = pop();
		if((op1 != 0 || op2 >= 0)&&(op1>0||(op2 -(int)op2)==0.0)){
			return pow(op1,op2);
		}
		else{
			printf("Domain error");
		}
	}
	else{
		printf("error: unkown command %s\n",s);
		
	}
	return 0.0;
}

