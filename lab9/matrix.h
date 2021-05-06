#ifndef _matrix_h_
#define _matrix_h_

struct Matrix {
	int** matrix;
	int row = 0;// колво строк
	int column = 0;// колво столбцов
};

Matrix matrix_multiplication(Matrix A, Matrix B);
void matrix_creating(Matrix& X);
void matrix_filling(Matrix& X);
void matrix_printing(Matrix& X);
void free_matrix(Matrix& X);
int  permanent_matrix(Matrix& X);
int step_find(int& res, int a[], Matrix& X, int stroka);
bool check(int val, int* mass, int lenght);
#endif