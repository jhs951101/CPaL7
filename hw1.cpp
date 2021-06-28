#include "matrix.h"  // 행렬 클래스 구현

#include "fraction.h"  // 분수 클래스 구현

#include "reverse.h"  // 거꾸로 문장 출력

#include "word.h"  // 끝말잇기 게임

#include "updown.h"  // Up & Down 게임

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
	int n1, d1;  // n1: '분수1'의 분자, d1: '분수1'의 분모
	cout << "Input the first fraction: ";
	cin >> n1 >> d1;
	Fraction a(n1, d1);  // a: 분수1

	int n2, d2;  // n2: '분수2'의 분자, d2: '분수2'의 분모
	cout << "Input the second fraction: ";
	cin >> n2 >> d2;	
	Fraction b(n2, d2);  // b: 분수2

	Fraction A, B, C, D;  // A: 두 분수의 덧셈, B: 두 분수의 뻴셈, C: 두 분수의 곱셈, D: 두 분수의 나눗셈

	A = a+b;  // 두 분수에 대한 덧셈 및 출력
	A.print();

	B = a-b;  // 두 분수에 대한 뻴셈 및 출력
	B.print();

	C = a*b;  // 두 분수에 대한 곱셈 및 출력
	C.print();

	D = a/b;  // 두 분수에 대한 나눗셈 및 출력
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

		Matrix a(r, c);  // a: 행렬1
		a.initializeMatrix(r, c, true);  // 행렬a 세팅
		a.printMatrix();  // 행렬a 출력

		Matrix b(r, c);  // b: 행렬2
		b.initializeMatrix(r, c, true);  // 행렬b 세팅
		b.printMatrix();  // 행렬b 출력

		Matrix A(r, c), B(r, c), C(r, r);  // A: 두 행렬의 덧셈, B: 두 행렬의 뺄셈, C: 두 행렬의 곱셈
		A.initializeMatrix(r, c, false);  // 덧셈 행렬 세팅
		B.initializeMatrix(r, c, false);  // 뻴셈 행렬 세팅
		C.initializeMatrix(r, r, false);  // 곱셈 행렬 세팅

		A = a+b; // 두 행렬에 대한 덧셈 수행
		B = a-b; // 두 행렬에 대한 뻴셈 수행
		C = a*b; // 두 행렬에 대한 곱셈 수행

		A.printMatrix();  // 덧셈 결과 출력
		B.printMatrix();  // 뻴셈 결과 출력
		C.printMatrix();  // 곱셈 결과 출력
		
	}while( (r>=1 && r<=10) && (c>=1 && c<=10) );

	return 0;
}