#pragma once
#include <string>

using namespace std;

class UpDownGame
{
private:
  int rand_num;
  int num_players;
  string* players;

  void inputPlayers();
  void inputNumber();
  void generateRandomNumber();

public:
  UpDownGame();
  ~UpDownGame();

  void startGame();
};