/*
 ============================================================================
 Name        : ex2.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Find the length of a String
 ============================================================================
 */
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
char str[MAX_SIZE];
int counter = 0,length = 0;

int main(void) {
	/*get string from user*/
	printf("Enter a string: ");
	fflush(stdout);
	gets(str);
	/*calculate length of the string*/
	length = 0;
	while(str[length] != 0){
		length++;
	}
	/*print the length*/
	printf("Length of string: %d",length);
	return 0;
}
