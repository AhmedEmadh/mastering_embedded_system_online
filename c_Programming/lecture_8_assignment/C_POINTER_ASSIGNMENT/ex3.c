#include <stdio.h>

/*
 ============================================================================
 Name        : ex3.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : reverse string.
 ============================================================================
 */
int getStrLength(char str[]){
	int i = 0;
	while(str[i] != 0){
		i++;
	}
	return i;
}
void swapChar(char* c1,char* c2){
	char temp;
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
void reverse_string(char str[]){
	int length = getStrLength(str);
	int i = 0;
	int j = length-1-i;
	while(i<j){
		swapChar(&str[i],&str[j]);
		i++;
		j--;
	}
}
int main(void){
	char str[20];
	printf("Input a string : ");
	fflush(stdout);
	gets(str);
	fflush(stdin);
	reverse_string(str);
	printf("Reverse of the string is : %s",str);
}
