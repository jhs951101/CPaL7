#include "phonebook.h"  // ��ȭ��ȣ�� �Է� �� �˻�

#include "circle.h"  // ���� ���� ����

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

int main(){

	// "Exercise1"
	CircleManager h6;
	h6.inputCircles();
	h6.outputResults();


	// "Exercise2"
	PhoneBook h7;
	h7.inputPhoneBook();
	h7.findPhoneBook();

	return 0;
}