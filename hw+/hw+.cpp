#include "phonebook.h"  // 전화번호부 입력 및 검색

#include "circle.h"  // 원의 개수 세기

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