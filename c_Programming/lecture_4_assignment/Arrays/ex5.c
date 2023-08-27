/*
 ============================================================================
 Name        : ex5.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Search an element in Array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int no_of_elements;
int arr[MAX_SIZE],counter,element,location = -1;
int main(void) {
	/*get number of elements*/
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&no_of_elements);
	/*generate elements*/
	for(counter=0;counter<no_of_elements;counter++){
		arr[counter] = (counter + 1) * 11;
	}
	/*print generated elements*/
	for(counter=0;counter<no_of_elements;counter++){
			printf("%d ",arr[counter]);
	}
	printf("\n");
	/*get element to be searched*/
	printf("Enter the elements to be searched : ");
	fflush(stdout);
	scanf("%d",&element);
	/*get the location of the element*/
	for(counter=0;counter<no_of_elements;counter++){
		if(arr[counter]==element){
			location = counter;
		}
	}
	/*print the location*/
	if(location != -1){
		printf("Number found at the location = %d",location + 1);
	}else{
		printf("Number not found ");
	}

	return 0;
}
