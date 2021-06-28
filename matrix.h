#pragma once

class Matrix
{
private:
    int row;
    int column;
    int table[100][100];

   void setRandomMatrix();

public:
    Matrix(int r = 1, int c = 1);
    void initializeMatrix(int row, int column, bool rand_option);
    void setMatrixValue(int row_pos, int col_pos, int value);
    int getMatrixValue(int row_pos, int col_pos);
    void printMatrix();

	Matrix operator+(Matrix & b);
    Matrix operator-(Matrix & b);
    Matrix operator*(Matrix & b);

};