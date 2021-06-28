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

	int len = text.length()-1;  // len: �ؽ�Ʈ�� ���̿� 1��ŭ �� ���� ����
	int a = 0, b = 0;  // a: �ܾ��� ������, b: �ܾ��� ����
					   // a, b: �ܾ �迭�� �����ϱ� ���� ����ϴ� ����
	int x = 0;  // x: ���� ����, �ܾ��� ������ �ǹ��ϱ⵵ ��
	string arr[100];  // arr[100]: ������ ���� �ܾ���� �����ϴ� �ӽ� �迭

	for(int i=0; i<=len; i++){

		if(text.substr(i,1) == " " || i == len){  // ������ �߰��ϰų� ���� ���� ���� ���
			b = i;  // ������ ����
			arr[x] = text.substr(a, b-a+1); // �ܾ ����� ����
			a = i+1;  // �̸� �������� ���� ���ʿ� ����

			if(i == len) arr[x] += " ";  // ���� ������ �ܾ ������ ���ս�Ŵ

			x++;
		}
	}

	this->num = x;  // ���� �ܾ��� ������ ������

	this->words = new string[x];  // words[]: ������ ���� �ܾ���� �����ϴ� �迭(��¥)

	for(int i=0; i<x; i++)
		this->words[i] = arr[i];  // �ܾ���� ���ʷ� �迭�� ������

}

void ReverseText::outputReverseText(){

	int cnt = this->num;  // cnt: �ܾ��� ����

	for(int i=0; i<=cnt-1; i++)
		cout << this->words[i];  // ������ ���������� ��½�Ŵ

	cout << endl;

	for(int i=cnt-1; i>=0; i--)
		cout << this->words[i];  // ������ ������ ��½�Ŵ

	cout << endl;

}