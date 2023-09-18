/*
 ============================================================================
 Name        : ex2.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Add two distances
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
struct SDistance{
	int m_feet;
	float m_inch;
};
void ReadDistance(struct SDistance* d){
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&d->m_feet);
	fflush(stdin);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d->m_inch);
	fflush(stdin);
}
struct SDistance SumDistances(struct SDistance* d1,struct SDistance* d2){
	struct SDistance sum;
	sum.m_feet = d1->m_feet + d2->m_feet;
	sum.m_inch = d1->m_inch + d2->m_inch;
	return sum;
}
void PrintDistance(struct SDistance* d){
	int feet;
	float inch;
	feet = d->m_feet + (int)((d->m_inch)/12);
	inch = (float)(((int)(d->m_inch * 10))%12)/10;
	printf("%d'-%.1f",feet,inch);
	fflush(stdout);
}

int main() {
	struct SDistance d1,d2,sum;
	/* read distances */
	printf("Enter information for 1st distance\n");
	fflush(stdout);
	ReadDistance(&d1);
	fflush(stdin);
	printf("Enter information for 2nd distance\n");
	fflush(stdout);
	ReadDistance(&d2);
	fflush(stdin);
	/* sum distances */
	sum = SumDistances(&d1,&d2);
	/* print distances */
	PrintDistance(&sum);
    return 0;
}

