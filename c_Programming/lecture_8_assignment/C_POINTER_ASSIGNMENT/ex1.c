#include <stdio.h>

/*
 ============================================================================
 Name        : ex1.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : how to handle the pointers in the program.
 ============================================================================
 */

int main(void){
	int m = 29;
	printf("Address of m : 0x%p\nValue of m : %d\n\n",&m,m);
	int *ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%p\nContent of pointer ab : %d\n\n",ab,*ab);
	m = 34;
	printf("The Value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%p\nContent of pointer ab : %d\n\n",ab,*ab);
	*ab = 7;
	printf("The pointer variable ab is assigned with the value %d now.\n Value of m : %d\n",*ab,ab);
	printf("Address of m : 0x%p\nValue of m : %d\n\n",&m,m);

	return 0;
}
