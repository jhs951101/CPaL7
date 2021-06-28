#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Matrix::setRandomMatrix(){

	int r = this->row;  // r: row을 저장
    int c = this->column;  // c: column을 저장

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++)
			this->table[x][y] = rand() % 30 +1;  // 행렬에 임의의 값을 넣음

}

Matrix::Matrix(int r, int c){

	this->row = r;
	this->column = c;
}

void Matrix::initializeMatrix(int row, int column, bool rand_option){

	this->row = row;
	this->column = column;

	if(rand_option == true) setRandomMatrix();

}

void Matrix::setMatrixValue(int row_pos, int col_pos, int value){

	this->table[row_pos][col_pos] = value;
}

int Matrix::getMatrixValue(int row_pos, int col_pos){

	return this->table[row_pos][col_pos];
}

void Matrix::printMatrix(){

	int r = this->row;  // r: row을 저장
    int c = this->column;  // c: column을 저장

	for(int x=0; x<r; x++){
		for(int y=0; y<c; y++)
			cout << setw(5) << this->table[x][y];  // 출력

		cout << endl;
	}

	cout << endl;

}

Matrix Matrix::operator+(Matrix & b){

	int r = this->row;  // r: row을 저장
	int c = this->column;  // c: column을 저장

	Matrix C(r,c);  // C: 두 행렬의 덧셈
	C.initializeMatrix(r, c, false);  // 두 행렬의 덧셈에 대한 행렬의 행과 열을 세팅

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++){
			int v1 = this->table[x][y];  // v1: 행렬1의 값을 저장
			int v2 = b.table[x][y];  // v2: 행렬2의 값을 저장
			C.setMatrixValue(x, y, v1+v2);  // 덧셈을 수행
		}

	return C;

}

Matrix Matrix::operator-(Matrix & b){

	int r = this->row;  // r: row을 저장
	int c = this->column;  // c: column을 저장

	Matrix C(r,c);  // C: 두 행렬의 뻴셈
	C.initializeMatrix(r, c, false);  // 두 행렬의 뻴셈에 대한 행렬의 행과 열을 세팅

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++){
			int v1 = this->table[x][y];  // v1: 행렬1의 값을 저장
			int v2 = b.table[x][y];  // v2: 행렬2의 값을 저장
			C.setMatrixValue(x, y, v1-v2);  // 뻴셈을 수행
		}

	return C;

}

Matrix Matrix::operator*(Matrix & b){

	int r = this->row;  // r: row을 저장
	int c = this->column;  // c: column을 저장

	Matrix C(r, r);  // C: 두 행렬의 곱셈
	C.initializeMatrix(r, r, false);  // 두 행렬의 곱셈에 대한 행렬의 행과 열을 세팅

	Matrix B_t(c, r);  // B_t: 행렬2의 전치행렬
	B_t.initializeMatrix(c, r, false);  // 행렬 B_t 의 행과 열을 세팅

	int v1, v2, v3;

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++){
			v1 = b.table[x][y];  // 행렬2 의 값을 불러옴
			B_t.setMatrixValue(y, x, v1);  // 행렬 B의 전치행렬을 세팅함
		}

	for(int x=0; x<r; x++)
		for(int y=0; y<r; y++)
			C.setMatrixValue(x, y, 0);  // 두 행렬의 곱셈을 위해 우선 곰셈 행렬의 값들을 모두 0으로 세팅

	for(int x=0; x<r; x++)
		for(int y=0; y<r; y++)
			for(int i=0; i<c; i++){

				v1 = C.getMatrixValue(x, y);  // 곱셈 행렬의 이전 값을 불러옴

				v2 = this->table[x][i];  // 행렬1의 값을 저장
				v3 = B_t.getMatrixValue(i, y);  // 전치행렬의 값을 저장

				v1 += v2*v3;  // 불러온 두 값을 곱한 후 누적시킴
				C.setMatrixValue(x, y, v1);  // 곱셈 행렬에 값을 저장
			}

	return C;

}