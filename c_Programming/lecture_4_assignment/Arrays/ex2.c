/*
 ============================================================================
 Name        : ex2.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : average using arrays
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float array[100];
int size,counter;
float average = 0;
int main(void) {
	/*take size from the user*/
	printf("Enter the numbers of data: ");
	fflush(stdout);
	scanf("%d",&size);
	/*take numbers from the user and calculating average*/
	for(counter = 0;counter<size;counter++){
		printf("%d. Enter number: ",counter+1);
		fflush(stdout);
		scanf("%f",&array[counter]);
		printf("\n");
		average += array[counter];
	}
	average /= size;
	printf("Average = %.2f",average);
	return 0;
}
