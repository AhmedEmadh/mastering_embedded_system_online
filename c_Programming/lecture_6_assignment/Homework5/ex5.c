/*
 ============================================================================
 Name        : ex5.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Find Area of a circle
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
struct SCircle{
	float m_radius;
};
float CalculateAreaOfCircle(struct SCircle* c){
	float pi = 3.14;
	float area = pi * c->m_radius * c->m_radius;
	return area;
}
void GetCircle(struct SCircle* c){
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&c->m_radius);
	fflush(stdin);
}
void printCircleArea(struct SCircle* c){
	float area = CalculateAreaOfCircle(c);
	printf("Area=%.2f",area);
	fflush(stdout);
}
int main() {
	struct SCircle circle;
	GetCircle(&circle);
	printCircleArea(&circle);
    return 0;
}

