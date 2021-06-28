#include "updown.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void UpDownGame::inputPlayers(){

	int n;  // n: 플레이어의 수를 입력받기 위한 변수

	do{
		cout << "Input the number of players: ";
		cin >> n;  // 플레이어의 수를 입력받음
	}while( n< 2 || n> 10 );  // 조건을 만족해야 프로그램이 진행됨

	this->num_players = n;
	this->players = new string[n];

	for(int i=0; i<n; i++){
		cout << "Input the name: ";
		cin >> this->players[i];  // 플레이어의 이름을 입력받음
	}

}

void UpDownGame::inputNumber(){

	int cnt = 1;  // cnt: 진행 횟수(Iteration)
	int i = 0;  // i: 플레이어의 순서가 차례대로 돌아가게 하기 위해 사용
	int num;  // num: 숫자를 입력받기 위한 변수

	do{

		cout << "Iteration: " << cnt << endl;
		cout << "This is " << this->players[i] << endl;
		cout << "Input the number: ";
		cin >> num;  // 숫자를 입력받음

		if (num == this->rand_num){  // 입력한 숫자가 정답과 같을 경우 게임종료
			cout << "The winner is " << this->players[i] << endl;
			cout << "Your number is matched." << endl;
			break;
		}
		else if( num > this->rand_num )  // 입력한 숫자가 정답보다 클 경우 DOWN 출력
			cout << "Down" << endl;
		else                             // 입력한 숫자가 정답보다 작을 경우 UP 출력
			cout << "Up" << endl;

		if(i == this->num_players-1) i = 0;  // 순서가 차례대로 돌아가게 하기 위해 사용
		else i++;
		
		cnt++;

	}while( num != this->rand_num );

}

void UpDownGame::generateRandomNumber(){

	srand((unsigned)time(NULL));

	this->rand_num = rand() % 501;  // 정답용 숫자를 임의로 설정함

}

UpDownGame::UpDownGame(){

}

UpDownGame::~UpDownGame(){

	delete[] this->players;

}

void UpDownGame::startGame(){

	this->generateRandomNumber();  // 정답용 숫자를 임의로 설정함

	this->inputPlayers();  // 플레이어 숫자 및 이름을 입력 받음

	this->inputNumber();  // 단어를 입력받으면서 게임을 진행함

}