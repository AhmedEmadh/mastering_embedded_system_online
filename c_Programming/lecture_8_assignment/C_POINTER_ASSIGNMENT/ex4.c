#include <stdio.h>

/*
 ============================================================================
 Name        : ex4.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : reverse array.
 ============================================================================
 */
int getStrLength(char str[]){
	int i = 0;
	while(str[i] != 0){
		i++;
	}
	return i;
}
void swapChar(char* c1,char* c2){
	char temp;
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
void reverse_string(char str[]){
	int length = getStrLength(str);
	int i = 0;
	int j = length-1-i;
	while(i<j){
		swapChar(&str[i],&str[j]);
		i++;j--;
	}
}
void swapInt(int* n1, int* n2){
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}
void reverseArray(int arr[],int n){
	int i =0;
	int j = n-1;
	while(i<j){
		swapInt(&arr[i],&arr[j]);
		i++;
		j--;
	}
}
int getArray(int arr[]){
	int num;
	/* get the num of elements */
	printf("Enter Number of Array elements : ");
	fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);
	int i;
	/*get the elements*/
	for(i=0;i<num;i++){
		printf("arr[%d] = ",i);
		fflush(stdout);
		scanf("%d",&arr[i]);
		fflush(stdin);
	}
	fflush(stdout);
	/* return num of elements */
	return num;
}
printArray(int arr[],int n){
	printf("the elements of the array are : ");
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	fflush(stdout);
}
int main(void){
	int arr[20];
	int n = getArray(arr);
	reverseArray(arr,n);
	printArray(arr,n);
}
