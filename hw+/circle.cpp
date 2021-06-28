#include "circle.h"
#include <iostream>

using namespace std;

Circle::Circle(){

}

Circle::~Circle(){
	
}

double Circle::getRadius(){

	return this->radius;
}

void Circle::setRadius(double r){

	this->radius = r;
}

double Circle::calculateArea(){

	double area;  // area: ���� ���̸� �����ϴ� ����
	area = this->radius * this->radius * 3.14;  // ���� ���̸� ����

	return area;
}

CircleManager::CircleManager(){

}

CircleManager::~CircleManager(){

	delete[] this->circles;
}

void CircleManager::inputCircles(){
	  
	int n;  // n: ���� ������ �Է¹ޱ� ���� ����
	cout << "Input the number of circles: ";
	cin >> n;  // ���� ������ �Է¹���

	this->num = n;

	this->circles = new Circle[n];

	for(int i=0; i<n; i++){

		int r;  // r: �������� ���̸� �Է¹ޱ� ���� ����

		cout << "Input the radius: ";
		cin >> r;  // �������� ���̸� �Է¹���

		this->circles[i].setRadius(r);  // �ش� ���� �������� ����

		this->circles[i].calculateArea();  // ���� ���̸� �����
	}	  
}

void CircleManager::outputResults(){

	int cnt = 0;  // cnt: ���̰� 100���� ū ���� ������ �����ϴ� ����

	for(int i=0; i<this->num; i++){

		double r = circles[i].getRadius();  // r: �������� ���̸� ����
		double area = r * r * 3.14;  // area: ���� ����

		if(area > 100) cnt++;  // ���� ���̰� 100���� ũ�� cnt�� +1��
		 
		cout << "The area of radius " << r << " is " << area << endl;  // ���� �������� ���� ���
	}

	cout << "The number of circles whose area is more than 100 is " << cnt << endl;  // ���̰� 100���� ū ���� ���� ���
}