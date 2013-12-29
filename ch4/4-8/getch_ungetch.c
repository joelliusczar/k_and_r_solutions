#include <stdio.h>

#define BUFSIZE 100

char bufch = 0;

int getch()
{
	 if(bufch != 0){
	 	char temp = bufch;
	 	bufch = 0;
	 	return temp;
	 }
	 else{
		 return getchar();
	 }
}

void ungetch(int c)
{
	bufch = c;
}


