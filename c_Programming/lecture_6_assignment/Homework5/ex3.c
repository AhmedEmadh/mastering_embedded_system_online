/*
 ============================================================================
 Name        : ex3.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Add Tow Complex Numbers
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
struct SComplex{
	float m_real;
	float m_img;
};
struct SComplex addComplex(struct SComplex comp1,struct SComplex comp2){
	struct SComplex result;
	result.m_real = comp1.m_real + comp2.m_real;
	result.m_img = comp1.m_img + comp2.m_img;
	return result;
}
void getComplex(struct SComplex* num){
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f%f",&num->m_real,&num->m_img);
	fflush(stdin);
}
void printComplex(struct SComplex c){
	printf("%.1f+%.1fi",c.m_real,c.m_img);
}
int main() {
	struct SComplex num1,num2,sum;
	/* read 2 complex numbers */
	printf("For 1st complex number\n");
	fflush(stdout);
	getComplex(&num1);
	fflush(stdin);
	printf("For 2nd complex number\n");
	fflush(stdout);
	getComplex(&num2);
	fflush(stdin);
	/* add two numbers */
	sum = addComplex(num1,num2);
	/* print result */
	printf("sum=");
	printComplex(sum);
    return 0;
}

