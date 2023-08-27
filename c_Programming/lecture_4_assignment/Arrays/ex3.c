/*
 ============================================================================
 Name        : ex3.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Transpose of a matrix
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int max_row, max_column;
int row, column;
int matrix[10][10];
int matrix_transpose[10][10];
int main(void) {
	/*get rows and columns from user*/
	printf("Enter rows and column of matrix: ");
	fflush(stdout);
	scanf("%d",&max_row);
	scanf("%d",&max_column);
	/*get elements of the matrix from user*/
	printf("Enter elements of the matrix:\n");
	for(row = 0;row<max_row;row++){
		for(column = 0;column<max_column;column++){
			printf("Enter elements a%d%d: ",row+1,column+1);
			fflush(stdout);
			scanf("%d",&matrix[row][column]);
		}
	}
	/*print Entered matrix*/
	printf("Entered Matrix:\n");
	for(row=0;row<max_row;row++){
		for(column=0;column<max_column;column++){
			printf("%d ",matrix[row][column]);
		}
		printf("\n");
	}
	/*calculate transpose of matrix*/
	for(row=0;row<max_row;row++){
		for(column=0;column<max_column;column++){
			matrix_transpose[column][row] = matrix[row][column];

		}
	}
	/*print new matrix*/
	printf("Transpose of Matrix:\n");
	for(row=0;row<max_column;row++){
		for(column=0;column<max_row;column++){
			printf("%d ",matrix_transpose[row][column]);

		}
		printf("\n");
	}
	return 0;
}
