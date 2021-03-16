#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main() {
	Matrix A;
	Matrix B;
	
	printf("Enter the number of rows 1 of the matrix\n");
	scanf("%d", &A.row);
	if (A.row <= 0) {
		printf("Error, invalid data");
		return -1;
	}
	printf("Enter the number of columns 1 of the matrix\n");
	scanf("%d", &A.column);
	if (A.column <= 0) {
		printf("Error, invalid data");
		return -1;
	}
	printf("Enter the number of rows 2 of the matrix\n");
	scanf("%d", &B.row);
	if (B.row <= 0) {
		printf("Error, invalid data");
		return -1;
	}
	printf("Enter the number of columns 2 of the matrix\n");
	scanf("%d", &B.column);
	if (B.column <= 0) {
		printf("Error, invalid data");
		return -1;
	}
	
	matrix_creating(A);
	matrix_creating(B);

	srand(time(NULL));
	matrix_filling(A);
	matrix_filling(B);

	printf("Matrix A\n");
	matrix_printing(A);
	printf("\n");

	printf("Matrix B\n");
	matrix_printing(B);
	printf("\n");

	Matrix result = matrix_multiplication(A, B);
	printf("Matrix result \n");
	matrix_printing(result);
	
	free_matrix(A);
	free_matrix(B);
	free_matrix(result);
	
	return 0;
}