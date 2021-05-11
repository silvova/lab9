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
	 if (X.matrix) {
		for (int i = 0; i < X.row; i++) {
			 X.matrix[i] = (int*)malloc(X.column * sizeof(int));
			 if (!X.matrix[i]) {
				 exit(-1);
			 }
		}
	}
	 else { exit(-1); }
}

void matrix_filling(Matrix& X) {
	for (int i = 0; i < X.row; i++) {
		for (int j = 0; j < X.column; j++) {
			X.matrix[i][j] = rand() % 10;
		}
	}
}

void matrix_printing(Matrix& X) {
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

int  permanent_matrix(Matrix& X) {
	int res = 0;
	int* mass = (int*)malloc(X.column * sizeof(int));
	int result = step_find(res, mass, X, 0);
	free(mass);
	return result;
}


//mass[] - массив с индексами строк(показывает, какие позиции в строке свободны)
//stroka - индекс текущей строки
int step_find(int& res,int mass[], Matrix& X ,int stroka) {
	int step_res = 0;//результат умножения одной уникальной последовательности
	if (stroka == 0) {//для перебора первой строчки
		for (int i = 0; i < X.column; i++) {
			if (X.row == 1) {
				res += X.matrix[0][i];
			}
			mass[stroka] = i;
			res += step_find(res, mass, X, stroka + 1);
		}
		return res;
	}
	for (int i = 0; i < X.column; i++) {//для подсчета всех вохможных сочетаний с i элементом из первой строки
		if (check(i, mass, stroka)) {
			mass[stroka] = i;
			if (stroka != X.row - 1) {
				step_find(res, mass, X, stroka + 1);
			}
			else {
				step_res = 1;
				for (int i = 0; i <= stroka; i++) {
					step_res *= X.matrix[i][mass[i]];
				}
				res += step_res;
			}
		}
	}
	return 0;
}

bool check(int val, int* mass, int lenght) {
	bool flag = true;
	for (int i = 0; i < lenght; i++) {
		if (val == mass[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}