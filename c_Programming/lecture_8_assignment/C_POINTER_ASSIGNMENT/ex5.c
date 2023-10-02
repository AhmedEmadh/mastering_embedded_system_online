#include <stdio.h>

/*
 ============================================================================
 Name        : ex6.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : show pointer to an array.
 ============================================================================
 */

typedef struct{
	char *Name;
	int Id;
} Employee;
int main(void){
	Employee e0 = {"Ahmed",1003};
	Employee e1 = {"Alex",1002};
	Employee* arr[2] = {&e0,&e1};
	Employee (* (*ptr)[2]) = &arr;
	printf("Employee Name: %s\n",(*((*ptr)[1])).Name);
	printf("Employee ID: %d\n",(*((*ptr)[1])).Id);
	return 0;

}
