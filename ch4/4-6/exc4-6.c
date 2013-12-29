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
