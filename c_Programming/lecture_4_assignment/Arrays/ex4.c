/*
 ============================================================================
 Name        : ex4.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Insert an element in an Array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int no_of_elements;
int arr[MAX_SIZE],counter,element,location;
int main(void) {
	/*get number of elements*/
	printf("Enter no of elements: ");
	fflush(stdout);
	scanf("%d",&no_of_elements);
	/*generate elements*/
	for(counter = 0;counter<no_of_elements;counter++){
		arr[counter] = counter + 1;
	}
	/*print generated elements*/
	for(counter = 0;counter<no_of_elements;counter++){
		printf("%d ",arr[counter]);
	}
	printf("\n");
	/*get element to be inserted*/
	printf("Enter the element to be inserted : ");
	fflush(stdout);
	scanf("%d",&element);
	/*get location*/
	printf("Enter the location: ");
	fflush(stdout);
	scanf("%d",&location);
	location--;
	/*insert element*/
	for(counter = no_of_elements;counter>location;counter--){
		arr[counter] = arr[counter-1];
	}
	arr[location] = element;
	no_of_elements++;
	/*print elements*/
	for(counter = 0;counter<no_of_elements;counter++){
			printf("%d ",arr[counter]);
		}
	return 0;
}
