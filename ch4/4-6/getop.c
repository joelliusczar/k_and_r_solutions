#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define VAR '='
#define ALPHA 'a'

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
