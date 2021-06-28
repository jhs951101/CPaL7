#include "word.h"
#include <string>
#include <iostream>

using namespace std;

void WordConnection::inputPlayers(){

	int n;  // n: 플레이어의 수를 입력받기 위한 변수

	do{
		cout << "Input the number of players: ";
		cin >> n;  // 플레이어의 수를 입력받음
	}while( n<2 || n>10 );  // 조건을 만족해야 프로그램이 진행됨

	this->num_players = n;
	this->players = new string[n];

	for(int i=0; i<n; i++){
		cout << "Input the name: ";
		cin >> this->players[i];  // 플레이어의 이름을 입력받음
	}

}

void WordConnection::inputWord(){

	int cnt = 1;  // cnt: 진행 횟수(Iteration)
	int i = 0;  // i: 플레이어의 순서가 차례대로 돌아가게 하기 위해 사용
	string str1, str2;  // str1: 이전 단어를 저장, str2: 현재 입력받은 단어를 저장
	string c1, c2;  // c1: 이전 단어의 제일 끝 문자, c2: 현재 단어의 제일 첫 문자
	int str1_len;  // str_len: 이전 단어의 길이

	do{

		cout << "Iteration: " << cnt << endl;
		cout << "This is " << this->players[i] << endl;
		cout << "Input your world: ";
		cin >> str2;  // 단어를 입력받음

		if(cnt == 1){  // 초기에는 단어를 비교하지 않고 입력만 받게 하기 위해 사용
			str1 = str2;
			i++;
			cnt++;
			continue;
		}

		str1_len = str1.length()-1;  // 이전 단어의 길이에서 1을 뺀 값을 저장

		c1 = str1.substr(str1_len,1);  // 이전 단어의 제일 끝 문자 저장
		c2 = str2.substr(0,1);  // 현재 단어의 제일 첫 문자 저장

		if(c1 != c2){  // 두 단어가 서로 연결되지 않을 경우 종료
			cout << str1 << " and " << str2 << " are unconnected" << endl;
			cout << this->players[i] << " is lost!" << endl;
			break;
		}

		str1 = str2;  // 현재 입력받은 단어를 이전 단어에 저장함

		if(i == this->num_players-1) i = 0;  // 순서가 차례대로 돌아가게 하기 위해 사용
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

	this->inputPlayers();  // 플레이어 숫자 및 이름을 입력 받음

	this->inputWord();  // 단어를 입력받으면서 게임을 진행함

}