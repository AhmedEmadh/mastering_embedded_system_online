/*
 ============================================================================
 Name        : ex1.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Prime Numbers
 ============================================================================
 */
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
int isPrime(int number){
	int i;

	if((number == 0)||(number == 1)||(number == 2)){
		return false;
	}
	for(i=2;i<number;i++){
		if(number % i == 0){
			return false;
		}
	}
	return true;
}
void printPrimeNumbers(int start,int end){
	int i;
	printf("Prime numbers between %d and %d are:",start,end);

	for(i=start+1;i<end;i++){
		if(isPrime(i) == true){
			printf(" %d",i);
		}
	}
	printf("\n");
	fflush(stdout);
}

int main(void){
	int num1,num2;
	printf("Enter two numbers(intervals): ");
	fflush(stdout);
	scanf("%d%d",&num1,&num2);
	fflush(stdin);
	printPrimeNumbers(num1,num2);
	return 0;
}
