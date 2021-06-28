#include "fraction.h"
#include <iostream>

using namespace std;

int Fraction::computeGCD(int x, int y){  // �ִ������� ���ϴ� �Լ�

	int min;  // min: x, y �� �ּҰ�

	if(x < y) min = x;
	else min = y;	    // �ּҰ��� ����

	for(int i=min; i>=1; i--)
		if(x%i == 0 && y%i == 0) return i;
			// i���� ��ȯ �� �ִ������� i��

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

	Fraction c;  // c: �� �м��� ����
	
	c.denominator = this->denominator * b.denominator;  // �� �м��� �������� �и� ����

	int n1 = this->numerator * b.denominator;  // n1: �м�1�� ����
	int n2 = this->denominator * b.numerator;  // n2: �м�2�� ����
	c.numerator = n1 + n2;  // �� �м��� �������� ���ڸ� ����

	int n = computeGCD(c.numerator, c.denominator);  // n: �м��� ������ ���ڿ� �и��� �ִ�����
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // ���ڿ� �и� �ִ������� ��������

	return c;

}

Fraction Fraction::operator-(Fraction & b){

	Fraction c;  // c: �� �м��� �y��
	
	c.denominator = this->denominator * b.denominator;  // �� �м��� �y������ �и� ����

	int n1 = this->numerator * b.denominator;  // n1: �м�1�� ����
	int n2 = this->denominator * b.numerator;  // n2: �м�2�� ����
	c.numerator = n1 - n2;  // �� �м��� �y������ ���ڸ� ����

	int n = computeGCD(c.numerator, c.denominator);  // n: �м��� �y���� ���ڿ� �и��� �ִ�����
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // ���ڿ� �и� �ִ������� ��������

	return c;

}

Fraction Fraction::operator*(Fraction & b){

	Fraction c;  // c: �� �м��� ����

	c.numerator = this->numerator * b.numerator;  // �� �м��� �������� ���ڸ� ����
	c.denominator = this->denominator * b.denominator;  // �� �м��� �������� �и� ����

	int n = computeGCD(c.numerator, c.denominator);  // n: �м��� ������ ���ڿ� �и��� �ִ�����
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // ���ڿ� �и� �ִ������� ��������

	return c;

}

Fraction Fraction::operator/(Fraction & b){

	Fraction c;  // c: �� �м��� ������

	int swap = b.numerator;  // swap: �� ���� �ٲٴ� ���� ���Ǵ� �ӽ� ����
	b.numerator = b.denominator;
	b.denominator = swap;
	  // �м�2�� ���ڿ� �и� ���� �ٲ���

	c.numerator = this->numerator * b.numerator;  // �� �м��� ���������� ���ڸ� ����
	c.denominator = this->denominator * b.denominator;  // �� �м��� ���������� �и� ����

	int n = computeGCD(c.numerator, c.denominator);  // n: �м��� �������� ���ڿ� �и��� �ִ�����
	c.numerator = c.numerator / n;
	c.denominator = c.denominator / n;  // ���ڿ� �и� �ִ������� ��������

	return c;

}

bool Fraction::operator==(Fraction & b){

	if(this->numerator == b.numerator && this->denominator == b.denominator)
		return true;  // �� �м��� ���ڳ���, �и𳢸� ���� ���� ��� true
	else
		return false;

}

bool Fraction::operator<(Fraction & b){

	if(this->denominator != b.denominator){  // �� �м��� �и� ���� �ٸ� ���

		int d = this->denominator * b.denominator;
		this->denominator = d;
		b.denominator = d;						 // �и� ���� ���� ����

		this->numerator = this->numerator * b.denominator;
		b.numerator = this->denominator * b.numerator;     // �޶��� �и� ���� ���ڸ� ����
	}

	if(this->numerator < b.numerator)  // ���� ���� �и� ������ �ִ� �� �м����� ���ڸ� ����
		return true;
	else
		return false;

}

bool Fraction::operator>(Fraction & b){

	if(this->denominator != b.denominator){  // �� �м��� �и� ���� �ٸ� ���

		int d = this->denominator * b.denominator;
		this->denominator = d;
		b.denominator = d;						 // �и� ���� ���� ����

		this->numerator = this->numerator * b.denominator;
		b.numerator = this->denominator * b.numerator;     // �޶��� �и� ���� ���ڸ� ����
	}

	if(this->numerator > b.numerator)  // ���� ���� �и� ������ �ִ� �� �м����� ���ڸ� ����
		return true;
	else
		return false;

}