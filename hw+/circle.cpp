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

	double area;  // area: 원의 넓이를 저장하는 변수
	area = this->radius * this->radius * 3.14;  // 원의 넓이를 구함

	return area;
}

CircleManager::CircleManager(){

}

CircleManager::~CircleManager(){

	delete[] this->circles;
}

void CircleManager::inputCircles(){
	  
	int n;  // n: 원의 갯수를 입력받기 위한 변수
	cout << "Input the number of circles: ";
	cin >> n;  // 원의 갯수를 입력받음

	this->num = n;

	this->circles = new Circle[n];

	for(int i=0; i<n; i++){

		int r;  // r: 반지름의 길이를 입력받기 위한 변수

		cout << "Input the radius: ";
		cin >> r;  // 반지름의 길이를 입력받음

		this->circles[i].setRadius(r);  // 해당 원의 반지름을 세팅

		this->circles[i].calculateArea();  // 원의 넓이를 계산함
	}	  
}

void CircleManager::outputResults(){

	int cnt = 0;  // cnt: 넓이가 100보다 큰 원의 갯수를 저장하는 변수

	for(int i=0; i<this->num; i++){

		double r = circles[i].getRadius();  // r: 반지름의 길이를 저장
		double area = r * r * 3.14;  // area: 원의 넓이

		if(area > 100) cnt++;  // 원의 넓이가 100보다 크면 cnt를 +1함
		 
		cout << "The area of radius " << r << " is " << area << endl;  // 원의 반지름의 길이 출력
	}

	cout << "The number of circles whose area is more than 100 is " << cnt << endl;  // 넓이가 100보다 큰 원의 갯수 출력
}