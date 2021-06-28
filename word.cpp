#include "word.h"
#include <string>
#include <iostream>

using namespace std;

void WordConnection::inputPlayers(){

	int n;  // n: �÷��̾��� ���� �Է¹ޱ� ���� ����

	do{
		cout << "Input the number of players: ";
		cin >> n;  // �÷��̾��� ���� �Է¹���
	}while( n<2 || n>10 );  // ������ �����ؾ� ���α׷��� �����

	this->num_players = n;
	this->players = new string[n];

	for(int i=0; i<n; i++){
		cout << "Input the name: ";
		cin >> this->players[i];  // �÷��̾��� �̸��� �Է¹���
	}

}

void WordConnection::inputWord(){

	int cnt = 1;  // cnt: ���� Ƚ��(Iteration)
	int i = 0;  // i: �÷��̾��� ������ ���ʴ�� ���ư��� �ϱ� ���� ���
	string str1, str2;  // str1: ���� �ܾ ����, str2: ���� �Է¹��� �ܾ ����
	string c1, c2;  // c1: ���� �ܾ��� ���� �� ����, c2: ���� �ܾ��� ���� ù ����
	int str1_len;  // str_len: ���� �ܾ��� ����

	do{

		cout << "Iteration: " << cnt << endl;
		cout << "This is " << this->players[i] << endl;
		cout << "Input your world: ";
		cin >> str2;  // �ܾ �Է¹���

		if(cnt == 1){  // �ʱ⿡�� �ܾ ������ �ʰ� �Է¸� �ް� �ϱ� ���� ���
			str1 = str2;
			i++;
			cnt++;
			continue;
		}

		str1_len = str1.length()-1;  // ���� �ܾ��� ���̿��� 1�� �� ���� ����

		c1 = str1.substr(str1_len,1);  // ���� �ܾ��� ���� �� ���� ����
		c2 = str2.substr(0,1);  // ���� �ܾ��� ���� ù ���� ����

		if(c1 != c2){  // �� �ܾ ���� ������� ���� ��� ����
			cout << str1 << " and " << str2 << " are unconnected" << endl;
			cout << this->players[i] << " is lost!" << endl;
			break;
		}

		str1 = str2;  // ���� �Է¹��� �ܾ ���� �ܾ ������

		if(i == this->num_players-1) i = 0;  // ������ ���ʴ�� ���ư��� �ϱ� ���� ���
		else i++;
		
		cnt++;

	}while(c1 == c2);

}

WordConnection::WordConnection(){

}

WordConnection::~WordConnection(){

	delete[] this->players;
}

void WordConnection::startGame(){

	this->inputPlayers();  // �÷��̾� ���� �� �̸��� �Է� ����

	this->inputWord();  // �ܾ �Է¹����鼭 ������ ������

}