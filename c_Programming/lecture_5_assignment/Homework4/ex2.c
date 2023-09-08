/*
 ============================================================================
 Name        : ex2.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Factorial with recursion
 ============================================================================
 */
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
int factorial(int num){
	if((num == 0)||(num == 1)){
		return 1;
	}
	return num * factorial(num-1);
}

int main(void){
	int num;
	printf("Enter an positive integer: ");
	fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);
	printf("Factorial of %d = %d",num,factorial(num));
	return 0;
}
