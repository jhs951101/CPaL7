#include "reverse.h"
#include <string>
#include <iostream>

using namespace std;

ReverseText::ReverseText(){

	
}

ReverseText::~ReverseText(){

	delete[] this->words;
}

void ReverseText::inputText(string text){

	int len = text.length()-1;  // len: 텍스트의 길이에 1만큼 뺀 값을 저장
	int a = 0, b = 0;  // a: 단어의 시작점, b: 단어의 끝점
					   // a, b: 단어를 배열에 저장하기 위해 사용하는 변수
	int x = 0;  // x: 보조 변수, 단어의 갯수를 의미하기도 함
	string arr[100];  // arr[100]: 문장을 나눈 단어들을 저장하는 임시 배열

	for(int i=0; i<=len; i++){

		if(text.substr(i,1) == " " || i == len){  // 공백을 발견하거나 문장 제일 끝일 경우
			b = i;  // 끝점을 놓음
			arr[x] = text.substr(a, b-a+1); // 단어를 나누어서 저장
			a = i+1;  // 미리 시작점을 공백 앞쪽에 놓음

			if(i == len) arr[x] += " ";  // 문장 마지막 단어에 공백을 결합시킴

			x++;
		}
	}

	this->num = x;  // 구한 단어의 갯수를 저장함

	this->words = new string[x];  // words[]: 문장을 나눈 단어들을 저장하는 배열(진짜)

	for(int i=0; i<x; i++)
		this->words[i] = arr[i];  // 단어들을 차례로 배열에 저장함

}

void ReverseText::outputReverseText(){

	int cnt = this->num;  // cnt: 단어의 갯수

	for(int i=0; i<=cnt-1; i++)
		cout << this->words[i];  // 문장을 순차적으로 출력시킴

	cout << endl;

	for(int i=cnt-1; i>=0; i--)
		cout << this->words[i];  // 문장을 역으로 출력시킴

	cout << endl;

}