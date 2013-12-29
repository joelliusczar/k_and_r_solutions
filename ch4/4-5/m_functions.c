#include <math.h>
#include <string.h>
#include <stdio.h>

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




