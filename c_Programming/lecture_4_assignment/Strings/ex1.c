/*
 ============================================================================
 Name        : ex1.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Find the frequency of characters in a string
 ============================================================================
 */
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
char str[MAX_SIZE];
int freq = 0,counter = 0;
char character;
int main(void) {
	/*get string from user*/
	printf("Enter a string: ");
	fflush(stdout);
	gets(str);
	/*get character from user*/
	printf("Enter a character to find frequency: ");
	fflush(stdout);
	scanf("%c",&character);
	/*calculate frequency of character*/
	counter = 0;
	while(str[counter] != 0){
		if(str[counter] == character){
			freq++;
		}
		counter++;
	}
	/*print the frequency*/
	printf("frequency of %c = %d",character,freq);
	return 0;
}
