/*
 * Filename:    strrindex.c
 * Author:      Joel Pridgen
 * Date:        18-NOV-2013
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 4-1, page 71
 *
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none. 
 */

/* strrindex:  return index of rightmost t in s, -1 if none */

#include <stdio.h>

int strrindex(char s[], char t[])
{
	int i,j,k,r;
	r = -1;
	for(i = 0;s[i] != '\0';i++){
		for(j=i,k=0;t[k] != '\0' && s[j] == t[k];j++,k++){;}
		if(t[k] == '\0' && k > 0){
			r =i;
		}
	}
	return r;
}
