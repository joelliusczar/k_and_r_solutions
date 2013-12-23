#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLEN 1000

int getlineKR(char s[],int lim);

main(void)
{
	double r, atof(char[]);
	char line[MAXLEN];
	getlineKR(line,MAXLEN);
	r = atof(line);
	printf("%g\n",r);
	
	return 0;
}

double atof(char s[])
{
	int i,sign,expsign,exp;
	double val,tentopow,e;
	for(i = 0;isspace(s[i]);i++){;}
	sign = s[i] == '-'? -1:1;
	if(s[i] == '+' || s[i] == '-'){
		i++;
	}
	for(val = 0.0;isdigit(s[i]);i++){
		val = val * 10.0 + (s[i] - '0');
	}
	if(s[i] == '.'){
		i++;
	}
	for(tentopow = 10.0;isdigit(s[i]);i++){
		val = val + (s[i] - '0')/tentopow;
		tentopow *= tentopow;
	}
	if(s[i] == 'e' || s[i] == 'E'){
		expsign = s[++i] == '-'?-1:1;
		if(s[i] == '-' || s[i] == '+'){
			i++;
		}
		for(exp = 0;isdigit(s[i]);i++){
			exp = exp * 10 +(s[i] -'0');
		}
		exp *= expsign;
		e = pow(10.0,exp);
		val *= e;
	}
	val *= sign;
	return val;
}
