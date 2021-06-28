#include "matrix.h"  // ��� Ŭ���� ����

#include "fraction.h"  // �м� Ŭ���� ����

#include "reverse.h"  // �Ųٷ� ���� ���

#include "word.h"  // �����ձ� ����

#include "updown.h"  // Up & Down ����

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

void testReverseText(){

	string text = "This is what I want to say";

	ReverseText t;

	t.inputText(text);
	t.outputReverseText();

}

int main(){

	// "Homework1"
	UpDownGame h1;
	h1.startGame();


	// "Homework2"
	WordConnection h2;
	h2.startGame();


	// "Homework3"
	testReverseText();


	// "Homework4"
	int n1, d1;  // n1: '�м�1'�� ����, d1: '�м�1'�� �и�
	cout << "Input the first fraction: ";
	cin >> n1 >> d1;
	Fraction a(n1, d1);  // a: �м�1

	int n2, d2;  // n2: '�м�2'�� ����, d2: '�м�2'�� �и�
	cout << "Input the second fraction: ";
	cin >> n2 >> d2;	
	Fraction b(n2, d2);  // b: �м�2

	Fraction A, B, C, D;  // A: �� �м��� ����, B: �� �м��� �y��, C: �� �м��� ����, D: �� �м��� ������

	A = a+b;  // �� �м��� ���� ���� �� ���
	A.print();

	B = a-b;  // �� �м��� ���� �y�� �� ���
	B.print();

	C = a*b;  // �� �м��� ���� ���� �� ���
	C.print();

	D = a/b;  // �� �м��� ���� ������ �� ���
	D.print();

	if(a == b) cout << "equal" << endl;
	else cout << "not equal" << endl;

	if(a > b){
		cout << "The first fraction is large" << endl;
		cout << "The second fraction is not large" << endl;
	} else{
		cout << "The second fraction is large" << endl;
		cout << "The first fraction is not large" << endl;
	}
	

	// "Homework5"
	int r, c;  // r: row, c: column

	do{
		cout << "Input the row and column: ";
		cin >> r >> c;

		if( !( (r>=1 && r<=10)&&(c>=1 && c<=10) ) ) break;

		srand(unsigned int(time(NULL)));

		Matrix a(r, c);  // a: ���1
		a.initializeMatrix(r, c, true);  // ���a ����
		a.printMatrix();  // ���a ���

		Matrix b(r, c);  // b: ���2
		b.initializeMatrix(r, c, true);  // ���b ����
		b.printMatrix();  // ���b ���

		Matrix A(r, c), B(r, c), C(r, r);  // A: �� ����� ����, B: �� ����� ����, C: �� ����� ����
		A.initializeMatrix(r, c, false);  // ���� ��� ����
		B.initializeMatrix(r, c, false);  // �y�� ��� ����
		C.initializeMatrix(r, r, false);  // ���� ��� ����

		A = a+b; // �� ��Ŀ� ���� ���� ����
		B = a-b; // �� ��Ŀ� ���� �y�� ����
		C = a*b; // �� ��Ŀ� ���� ���� ����

		A.printMatrix();  // ���� ��� ���
		B.printMatrix();  // �y�� ��� ���
		C.printMatrix();  // ���� ��� ���
		
	}while( (r>=1 && r<=10) && (c>=1 && c<=10) );

	return 0;
}