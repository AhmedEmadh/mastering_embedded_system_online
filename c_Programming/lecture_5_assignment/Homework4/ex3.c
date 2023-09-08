/*
 ============================================================================
 Name        : ex3.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Reverse Sentence using recursion
 ============================================================================
 */
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
void printReversed(char *str){
	if(*str != '\0'){
		printReversed(str+1);

	}else{
		return;
	}
	printf("%c",*str);
}
int main(void){

	char str[20];
	printf("Enter a Sentence: ");
	fflush(stdout);
	gets(str);
	fflush(stdin);
	printReversed(str);
	return 0;
}
