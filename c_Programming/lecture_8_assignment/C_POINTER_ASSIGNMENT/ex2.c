#include <stdio.h>
/*
 ============================================================================
 Name        : ex2.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : print all the alphabets using a pointer.
 ============================================================================
 */

int main(void){
	unsigned char alphabets[26];
	unsigned char* ptr = alphabets;
	int i;
	/* filling array with alphabets */
	for(i=0;i<26;i++){
		*(ptr + i) = i + 'A';

	}
	/*printing alphabets*/
	for(i=0;i<26;i++){
		printf("%c ",*(ptr + i));
	}
	return 0;
}
