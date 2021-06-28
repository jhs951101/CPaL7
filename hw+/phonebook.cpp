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

	int n = this->num;  // n: �ּҷ��� ����� ����

	this->people = new Person[this->num];

	string name, p_number;  // name: �̸��� �Է¹ޱ� ���� ����, p_number: �̸��� �Է¹ޱ� ���� ����

	for(int i=0; i<n; i++){

		cout << "Input the name: ";
		cin >> name;  // �̸��� �Է¹���
		this->people[i].setName(name);  // �̸��� ������

		cout << "Input the phone number: ";
		cin >> p_number;  // ����ȣ�� �Է¹���
		this->people[i].setPhoneNumber(p_number);  // ����ȣ�� ������
	}

}

void PhoneBook::findPhoneBook(){

	cout << endl;

	string f_name;  // f_name: Ư���� ����� �̸��� �Է¹ޱ� ���� ����
	cout << "Who do you want to find? ";
	cin >> f_name;  // �̸��� �Է¹���

	int n = this->num;  // n: �ּҷ��� ����� ����

	string name;  // name: �ּҷϿ� �ִ� ����� �̸��� �ҷ��� �� �����ϱ� ���� ����
	bool exist = false;

	for(int i=0; i<n; i++){

		name = this->people[i].getName();  // �ҷϿ� �ִ� ����� �̸��� �ҷ���

		if(f_name == name){
			string p_number = this->people[i].getPhoneNumber();  // p_number: �ּҷϿ� �ִ� ����ȣ �ҷ��� �� �����ϱ� ���� ����
			cout << "The phone number of " << f_name << " is " << p_number << endl;
		}
	}

}