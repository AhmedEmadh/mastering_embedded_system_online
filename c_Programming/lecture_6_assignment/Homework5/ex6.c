/*
 ============================================================================
 Name        : ex6.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Output of the program
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
union job{
	char name[32];
	float salary;
	int worker_no;
}u;
struct job1{
	char name[32];
	float salary;
	int worker_no;
}s;
int main() {
	printf("size of union=%d",sizeof(u));
	printf("\nsize of structure = %d",sizeof(s));
    return 0;
}

