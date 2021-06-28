#include "fraction.h"
#include <iostream>

using namespace std;

int Fraction::computeGCD(int x, int y){  // 최대공약수를 구하는 함수

	int min;  // min: x, y 중 최소값

	if(x < y) min = x;
	else min = y;	    // 최소값을 구함

	for(int i=min; i>=1; i--)
		if(x%i == 0 && y%i == 0) return i;
			// i값을 반환 시 최대공약수는 i임

}

Fraction::Fraction(int n, int d){

	this->numerator = n;
	this->denominator = d;
}

void Fraction::setNumerator(int numerator){

	this->numerator = numerator;
}

void Fraction::setDenominator(int denominator){

	this->denominator = denominator;
}

int Fraction::getNumerator(){

	return this->numerator;
}

int Fraction::getDenominator(){

	return this->denominator;
}

void Fraction::print(){

	cout << this->numerator << " / " << this->denominator << endl;
}  

Fraction Fraction::operator+(Fraction & b){

	Fraction c;  // c: 두 분수의 덧셈
	
	c.denominator = this->denominator * b.denominator;  // 두 분수의 덧셈에서 분모를 구함

	int n1 = this->numerator * b.denominator;  // n1: 분수1의 분자
	int n2 = this->denominator * b.numerator;  // n2: 분수2의 분자
	c.numerator = n1 + n2;  // 두 분수의 덧셈에서 분자를 구함

	int n = computeGCD(c.numerator, c.denominator);  // n: 분수의 덧셈의 분자와 분모의 최대공약수
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // 분자와 분모를 최대공약수로 나누어줌

	return c;

}

Fraction Fraction::operator-(Fraction & b){

	Fraction c;  // c: 두 분수의 뻴셈
	
	c.denominator = this->denominator * b.denominator;  // 두 분수의 뻴셈에서 분모를 구함

	int n1 = this->numerator * b.denominator;  // n1: 분수1의 분자
	int n2 = this->denominator * b.numerator;  // n2: 분수2의 분자
	c.numerator = n1 - n2;  // 두 분수의 뻴셈에서 분자를 구함

	int n = computeGCD(c.numerator, c.denominator);  // n: 분수의 뻴셈의 분자와 분모의 최대공약수
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // 분자와 분모를 최대공약수로 나누어줌

	return c;

}

Fraction Fraction::operator*(Fraction & b){

	Fraction c;  // c: 두 분수의 곱셈

	c.numerator = this->numerator * b.numerator;  // 두 분수의 곱셈에서 분자를 구함
	c.denominator = this->denominator * b.denominator;  // 두 분수의 곱셈에서 분모를 구함

	int n = computeGCD(c.numerator, c.denominator);  // n: 분수의 곱셈의 분자와 분모의 최대공약수
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // 분자와 분모를 최대공약수로 나누어줌

	return c;

}

Fraction Fraction::operator/(Fraction & b){

	Fraction c;  // c: 두 분수의 나눗셈

	int swap = b.numerator;  // swap: 두 값을 바꾸는 데에 사용되는 임시 변수
	b.numerator = b.denominator;
	b.denominator = swap;
	  // 분수2의 분자와 분모를 서로 바꿔줌

	c.numerator = this->numerator * b.numerator;  // 두 분수의 나눗셈에서 분자를 구함
	c.denominator = this->denominator * b.denominator;  // 두 분수의 나눗셈에서 분모를 구함

	int n = computeGCD(c.numerator, c.denominator);  // n: 분수의 나눗셈의 분자와 분모의 최대공약수
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // 분자와 분모를 최대공약수로 나누어줌

	return c;

}

bool Fraction::operator==(Fraction & b){

	if(this->numerator == b.numerator && this->denominator == b.denominator)
		return true;  // 두 분수의 분자끼리, 분모끼리 서로 같을 경우 true
	else
		return false;

}

bool Fraction::operator<(Fraction & b){

	if(this->denominator != b.denominator){  // 두 분수의 분모가 서로 다를 경우

		int d = this->denominator * b.denominator;
		this->denominator = d;
		b.denominator = d;						 // 분모를 서로 같게 해줌

		this->numerator = this->numerator * b.denominator;
		b.numerator = this->denominator * b.numerator;     // 달라진 분모에 따라 분자를 변경
	}

	if(this->numerator < b.numerator)  // 서로 같은 분모를 가지고 있는 두 분수에서 분자를 비교함
		return true;
	else
		return false;

}

bool Fraction::operator>(Fraction & b){

	if(this->denominator != b.denominator){  // 두 분수의 분모가 서로 다를 경우

		int d = this->denominator * b.denominator;
		this->denominator = d;
		b.denominator = d;						 // 분모를 서로 같게 해줌

		this->numerator = this->numerator * b.denominator;
		b.numerator = this->denominator * b.numerator;     // 달라진 분모에 따라 분자를 변경
	}

	if(this->numerator > b.numerator)  // 서로 같은 분모를 가지고 있는 두 분수에서 분자를 비교함
		return true;
	else
		return false;

}