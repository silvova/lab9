#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

//функция вычисления перманента марицы

int main() {
	Matrix A;

	printf("Enter the number of rows 1 of the matrix\n");
	while (scanf("%d", &A.row) != 1 || A.row <= 0) {
		printf("Error, invalid data. Try again:\n");
		while (getchar() != '\n') {
			;
		}
	}
	printf("Enter the number of columns 1 of the matrix\n");
	while (scanf("%d", &A.column) != 1 || A.column <= 0) {
		printf("Error, invalid data. Try again:\n");
		while (getchar() != '\n') {
			;
		}
	}

	matrix_creating(A);

	srand(time(NULL));
	matrix_filling(A);

	printf("Matrix A\n");
	matrix_printing(A);
	printf("\n");

	printf("Calculating permanent...\n");
	if (A.row <= A.column) {
		printf("Permanent of matrix: %d", permanent_matrix(A));
	}
	else {
		printf("Error, wrong matrix size for calculating permanent!\n");
	}

	free_matrix(A);

	return 0;
}