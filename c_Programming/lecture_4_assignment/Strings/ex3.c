/*
 ============================================================================
 Name        : ex3.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Reverse string
 ============================================================================
 */
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
char str[MAX_SIZE];
int counter = 0,length=0;
int start,end;
char temp;
int main(void) {
	/*get string from user*/
	printf("Enter the string: ");
	fflush(stdout);
	gets(str);
	/*calculate length of the string*/
	length = 0;
	while(str[length] != 0){
		length++;
	}
	end = length-1;
	while(end>start){
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	/*print the length*/
	printf("Reverse string is : %s",str);
	return 0;
}
