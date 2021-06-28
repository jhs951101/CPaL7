#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Matrix::setRandomMatrix(){

	int r = this->row;  // r: row�� ����
    int c = this->column;  // c: column�� ����

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++)
			this->table[x][y] = rand() % 30 +1;  // ��Ŀ� ������ ���� ����

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

	int r = this->row;  // r: row�� ����
    int c = this->column;  // c: column�� ����

	for(int x=0; x<r; x++){
		for(int y=0; y<c; y++)
			cout << setw(5) << this->table[x][y];  // ���

		cout << endl;
	}

	cout << endl;

}

Matrix Matrix::operator+(Matrix & b){

	int r = this->row;  // r: row�� ����
	int c = this->column;  // c: column�� ����

	Matrix C(r,c);  // C: �� ����� ����
	C.initializeMatrix(r, c, false);  // �� ����� ������ ���� ����� ��� ���� ����

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++){
			int v1 = this->table[x][y];  // v1: ���1�� ���� ����
			int v2 = b.table[x][y];  // v2: ���2�� ���� ����
			C.setMatrixValue(x, y, v1+v2);  // ������ ����
		}

	return C;

}

Matrix Matrix::operator-(Matrix & b){

	int r = this->row;  // r: row�� ����
	int c = this->column;  // c: column�� ����

	Matrix C(r,c);  // C: �� ����� �y��
	C.initializeMatrix(r, c, false);  // �� ����� �y���� ���� ����� ��� ���� ����

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++){
			int v1 = this->table[x][y];  // v1: ���1�� ���� ����
			int v2 = b.table[x][y];  // v2: ���2�� ���� ����
			C.setMatrixValue(x, y, v1-v2);  // �y���� ����
		}

	return C;

}

Matrix Matrix::operator*(Matrix & b){

	int r = this->row;  // r: row�� ����
	int c = this->column;  // c: column�� ����

	Matrix C(r, r);  // C: �� ����� ����
	C.initializeMatrix(r, r, false);  // �� ����� ������ ���� ����� ��� ���� ����

	Matrix B_t(c, r);  // B_t: ���2�� ��ġ���
	B_t.initializeMatrix(c, r, false);  // ��� B_t �� ��� ���� ����

	int v1, v2, v3;

	for(int x=0; x<r; x++)
		for(int y=0; y<c; y++){
			v1 = b.table[x][y];  // ���2 �� ���� �ҷ���
			B_t.setMatrixValue(y, x, v1);  // ��� B�� ��ġ����� ������
		}

	for(int x=0; x<r; x++)
		for(int y=0; y<r; y++)
			C.setMatrixValue(x, y, 0);  // �� ����� ������ ���� �켱 ���� ����� ������ ��� 0���� ����

	for(int x=0; x<r; x++)
		for(int y=0; y<r; y++)
			for(int i=0; i<c; i++){

				v1 = C.getMatrixValue(x, y);  // ���� ����� ���� ���� �ҷ���

				v2 = this->table[x][i];  // ���1�� ���� ����
				v3 = B_t.getMatrixValue(i, y);  // ��ġ����� ���� ����

				v1 += v2*v3;  // �ҷ��� �� ���� ���� �� ������Ŵ
				C.setMatrixValue(x, y, v1);  // ���� ��Ŀ� ���� ����
			}

	return C;

}