#ifndef _matrix_h_
#define _matrix_h_

struct Matrix {
	int** matrix = { 0 };
	int row = 0;
	int column = 0;
};

Matrix matrix_multiplication(Matrix A, Matrix B);
void matrix_creating(Matrix& X);
void matrix_filling(Matrix X);
void matrix_printing(Matrix X);
void free_matrix(Matrix& X);
#endif