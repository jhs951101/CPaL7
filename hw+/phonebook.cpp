#include "phonebook.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person(){

}

Person::~Person(){

}

string Person::getName(){

	return this->name;
}

void Person::setName(string name){

	this->name = name;
}

string Person::getPhoneNumber(){

	return this->phone_number;
}

void Person::setPhoneNumber(string phone_number){

	this->phone_number = phone_number;
}


PhoneBook::PhoneBook(){

}

PhoneBook::~PhoneBook(){

	delete[] this->people;
}

void PhoneBook::inputPhoneBook(){

	cout << "Input the number of people: ";
	cin >> this->num;

	int n = this->num;  // n: 주소록의 사람의 숫자

	this->people = new Person[this->num];

	string name, p_number;  // name: 이름을 입력받기 위한 변수, p_number: 이름을 입력받기 위한 변수

	for(int i=0; i<n; i++){

		cout << "Input the name: ";
		cin >> name;  // 이름을 입력받음
		this->people[i].setName(name);  // 이름을 세팅함

		cout << "Input the phone number: ";
		cin >> p_number;  // 폰번호를 입력받음
		this->people[i].setPhoneNumber(p_number);  // 폰번호를 세팅함
	}

}

void PhoneBook::findPhoneBook(){

	cout << endl;

	string f_name;  // f_name: 특정한 사람의 이름을 입력받기 위한 변수
	cout << "Who do you want to find? ";
	cin >> f_name;  // 이름을 입력받음

	int n = this->num;  // n: 주소록의 사람의 숫자

	string name;  // name: 주소록에 있는 사람의 이름을 불러온 후 저장하기 위한 변수
	bool exist = false;

	for(int i=0; i<n; i++){

		name = this->people[i].getName();  // 소록에 있는 사람의 이름을 불러옴

		if(f_name == name){
			string p_number = this->people[i].getPhoneNumber();  // p_number: 주소록에 있는 폰번호 불러온 후 저장하기 위한 변수
			cout << "The phone number of " << f_name << " is " << p_number << endl;
		}
	}

}