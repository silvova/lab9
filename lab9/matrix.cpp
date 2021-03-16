#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

Matrix matrix_multiplication(Matrix A, Matrix B) {

	if (A.column != B.row) {
		printf("Error, wrong matrix size!\n");
		exit(-1);
	}

	Matrix C;
	C.row = A.row;
	C.column = B.column;
	matrix_creating(C);

	for (int i = 0; i < C.row; i++) {
		for (int j = 0; j < C.column; j++) {
			C.matrix[i][j] = 0;
			for (int k = 0; k < A.column; k++) {
				C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
			}
		}
	}

	return C;
}

void matrix_creating(Matrix& X) {
	X.matrix = (int**)malloc(X.row * sizeof(int*));
	for (int i = 0; i < X.row; i++) {
		X.matrix[i] = (int*)malloc(X.column * sizeof(int));
	}
}

void matrix_filling(Matrix X) {
	for (int i = 0; i < X.row; i++) {
		for (int j = 0; j < X.column; j++) {
			X.matrix[i][j] = rand() % 10;
		}
	}
}

void matrix_printing(Matrix X) {
	for (int i = 0; i < X.row; i++) {
		for (int j = 0; j < X.column; j++) {
			printf("%d ", X.matrix[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(Matrix& X) {
	for (int i = 0; i < X.row; i++) { 
		free(X.matrix[i]);
	}
	free(X.matrix);
}