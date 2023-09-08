/*
 ============================================================================
 Name        : ex4.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Power of a Number using recursion
 ============================================================================
 */
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
int power(int num,int pow){
	if(pow == 0){
		return 1;
	}else if(pow == 1){
		return num;
	}
	return num * power(num,pow-1);
}
int main(void){
	int base_num,pow_num;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&base_num);
	fflush(stdin);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&pow_num);
	fflush(stdin);
	printf("%d^%d = %d",base_num,pow_num,power(base_num,pow_num));
	return 0;
}
