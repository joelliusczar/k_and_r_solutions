#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);
void ungets(char[]);

main(void)
{
	char c;
	char ms[] = "Hello this is the test input.\n"; 
	ungets(ms);
	while((c = getch()) != '\n'){
		putchar(c);
	}
	putchar('\n');
	
	return 0;
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

void ungets(char s[])
{
	int i = strlen(s);
	while(i-- > 0){
		ungetch(s[i]);
	}
}
