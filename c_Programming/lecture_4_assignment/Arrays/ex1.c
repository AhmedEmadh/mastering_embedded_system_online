/*
 ============================================================================
 Name        : ex1.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : sum of two matrices
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float a[2][2];
float b[2][2];
float sum[2][2];
int row,colomn;
int main(void) {
	/*Entering the elements of the first matrix*/
	printf("Enter the elements of 1st matrix\r\n");
	fflush(stdout);
	for(row=0;row<2;row++){
		for(colomn=0;colomn<2;colomn++){
			printf("Enter a%d%d: ",row+1,colomn+1);
			fflush(stdout);
			scanf("%f",&a[row][colomn]);
		}

	}
	/*Entering the elements of the second matrix*/
	printf("Enter the elements of 2nd matrix\r\n");
	for(row=0;row<2;row++){
		for(colomn=0;colomn<2;colomn++){
			printf("Enter b%d%d: ",row+1,colomn+1);
			fflush(stdout);
			scanf("%f",&b[row][colomn]);
		}
	}
	/*getting the sum of the matrix*/
	for(row=0;row<2;row++){
		for(colomn=0;colomn<2;colomn++){
			sum[row][colomn] = a[row][colomn] + b[row][colomn];
		}
	}
	/*printing the sum of the array*/
	printf("Sum Of Matrix:\n");
	for(row=0;row<2;row++){
		for(colomn=0;colomn<2;colomn++){
			printf("%.1f\t",sum[row][colomn]);
		}
		printf("\r\n");
	}
	return 0;
}
