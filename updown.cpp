#include "updown.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void UpDownGame::inputPlayers(){

	int n;  // n: �÷��̾��� ���� �Է¹ޱ� ���� ����

	do{
		cout << "Input the number of players: ";
		cin >> n;  // �÷��̾��� ���� �Է¹���
	}while( n< 2 || n> 10 );  // ������ �����ؾ� ���α׷��� �����

	this->num_players = n;
	this->players = new string[n];

	for(int i=0; i<n; i++){
		cout << "Input the name: ";
		cin >> this->players[i];  // �÷��̾��� �̸��� �Է¹���
	}

}

void UpDownGame::inputNumber(){

	int cnt = 1;  // cnt: ���� Ƚ��(Iteration)
	int i = 0;  // i: �÷��̾��� ������ ���ʴ�� ���ư��� �ϱ� ���� ���
	int num;  // num: ���ڸ� �Է¹ޱ� ���� ����

	do{

		cout << "Iteration: " << cnt << endl;
		cout << "This is " << this->players[i] << endl;
		cout << "Input the number: ";
		cin >> num;  // ���ڸ� �Է¹���

		if (num == this->rand_num){  // �Է��� ���ڰ� ����� ���� ��� ��������
			cout << "The winner is " << this->players[i] << endl;
			cout << "Your number is matched." << endl;
			break;
		}
		else if( num > this->rand_num )  // �Է��� ���ڰ� ���亸�� Ŭ ��� DOWN ���
			cout << "Down" << endl;
		else                             // �Է��� ���ڰ� ���亸�� ���� ��� UP ���
			cout << "Up" << endl;

		if(i == this->num_players-1) i = 0;  // ������ ���ʴ�� ���ư��� �ϱ� ���� ���
		else i++;
		
		cnt++;

	}while( num != this->rand_num );

}

void UpDownGame::generateRandomNumber(){

	srand((unsigned)time(NULL));

	this->rand_num = rand() % 501;  // ����� ���ڸ� ���Ƿ� ������

}

UpDownGame::UpDownGame(){

}

UpDownGame::~UpDownGame(){

	delete[] this->players;

}

void UpDownGame::startGame(){

	this->generateRandomNumber();  // ����� ���ڸ� ���Ƿ� ������

	this->inputPlayers();  // �÷��̾� ���� �� �̸��� �Է� ����

	this->inputNumber();  // �ܾ �Է¹����鼭 ������ ������

}