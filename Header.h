#pragma once
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <stdio.h>
using namespace std;

class Matrix {
private:
	int rows;
	int columns;
	float** m;

public:
//	Matrix();
	Matrix(int a, int b);
	Matrix(float **M);
	Matrix operator +(const Matrix& other);
	Matrix operator -(const Matrix& other);
	friend Matrix operator *(double real, const Matrix& other);
	Matrix operator *(const Matrix& other);
	friend std::ostream& operator <<(std::ostream& os, const Matrix& other);


};
/*
Matrix::Matrix() :rows(1), columns(1) {
	**m = 0;
}
*/
Matrix::Matrix(int a, int b) : rows(a), columns(b) {
	m = new float* [rows];
	for (int i = 0; i < rows; i++) {
		m[i] = new float[columns];
		for (int j = 0; j < columns; j++) {
			m[i][j] = 1;
		}
	}

}

Matrix::Matrix(float **M) : rows(sizeof(*M)), columns(sizeof(**M)) {
	m = new float* [rows];
	for (int i = 0; i < rows; i++) {
		m[i] = new float[columns];
		for (int j = 0; j < columns; j++) {
			m[i][j] = M[i][j];
		}
	}

}

Matrix Matrix::operator+(const Matrix& other) {
	float** M;
	if (other.rows != rows && other.columns != columns) {
		cout << "这两个矩阵大小不一，无法相加！" << endl;
	}
	else {
		M = new float* [rows];
		for (int i = 0; i < rows; i++) {
			*M = new float[columns];
			for (int j = 0; j < columns; j++) {
				M[i][j]=m[i][j] + other.m[i][j];
			}
		}
	}
	return Matrix(M);
}

Matrix Matrix::operator -(const Matrix& other) {
	float** M;
	if (other.rows != rows && other.columns != columns) {
		cout << "这两个矩阵大小不一，无法相减！" << endl;
	}
	else {
		M = new float* [rows];
		for (int i = 0; i < rows; i++) {
			*M = new float[columns];
			for (int j = 0; j < columns; j++) {
				M[i][j] = m[i][j] - other.m[i][j];
			}
		}
	}
	return Matrix(M);
}

Matrix operator *(double real, const Matrix& other) {
	float** M;
	M = new float* [other.rows];
	for (int i = 0; i < other.rows; i++) {
		M[i] = new float [other.columns];
		for (int j = 0; j < other.columns; j++) {
			M[i][j] = real * other.m[i][j];
		}
	}
	return Matrix(M);
}

Matrix Matrix::operator *(const Matrix& other) {
	float** M;
	if (columns != other.rows) {
		cout << "这两个矩阵无法相乘";
	}
	else {
		M = new float* [rows];
		for (int i = 0; i < rows; i++) {
			M[i] = new float[other.columns];
			for (int j = 0; j < other.columns; j++) {
				M[i][j] = 0;
				for (int a = 0; a < columns; a++) {
					M[i][j] += m[i][a] * other.m[a][j];
				}
			}
		}

	}
	return Matrix(M);
}

std::ostream& operator <<(std::ostream& os, const Matrix& other) {
	for (int i = 0; i < other.rows; i++) {
		for (int j = 0; j < other.columns; j++) {
			os << other.m[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}