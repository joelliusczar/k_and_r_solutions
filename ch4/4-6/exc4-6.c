#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define VAR '='
#define ALPHA 'a'

int getop(char []);
void push(double);
double pop(void);

main(void)
{
	int type,i;
	double op2, vars[26];
	char s[MAXOP];
	
	for(i = 0;i< 26;i++){
		vars[i] = 0.0;
	}
	
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
			case VAR:
				push(vars[tolower(s[1]) - 'a'] = pop());
				break;
			case ALPHA:
				push(vars[tolower(s[0]) - 'a']);
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

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t'){;}
	
	s[1] = '\0';
	if(c == '='){
		if(isalpha(s[1] = c = getch())){
			s[2] = '\0';
			return VAR;
		}
	}
	
	if(isalpha(c)){
		return ALPHA;
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
