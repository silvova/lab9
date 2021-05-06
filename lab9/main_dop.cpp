#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

//функция вычисления перманента марицы

int main() {
	Matrix A;

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

	matrix_creating(A);

	srand(3);
	matrix_filling(A);

	printf("Matrix A\n");
	matrix_printing(A);
	printf("\n");

	printf("Permanent of matrix: %d", permanent_matrix(A));


	free_matrix(A);

	return 0;
}