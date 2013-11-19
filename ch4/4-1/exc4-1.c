#include <stdio.h>

#define MAXLEN 1000

int getlineKR(char s[],int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ate";

main(void)
{
	char s[MAXLEN];
	getlineKR(s,MAXLEN);
	printf("%d\n",strrindex(s,pattern));
	
	return 0;
}


