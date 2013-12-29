#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define FUNCTION 'f'

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
