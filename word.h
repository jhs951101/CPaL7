#pragma once
#include <string>

using namespace std;

class WordConnection
{
private:
  int num_players;
  string* players;

  void inputPlayers();
  void inputWord();

public:
  WordConnection();
  ~WordConnection();

  void startGame();
};