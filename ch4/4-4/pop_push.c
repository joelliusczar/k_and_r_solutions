#include <stdio.h>

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

double peek()
{
	if(sp > 0){
		return val[sp-1];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void switchtoptwo()
{
	double temp;
	if(sp > 1){
		temp = val[sp -1];
		val[sp -1] = val[sp -2];
		val[sp -2] = temp;
	}
	else{
		printf("error: insufficient number of elements in stack. \n");
	}
}

void clearstack()
{
	while(sp >= 0){
		val[--sp] = 0.0;
	}
}
