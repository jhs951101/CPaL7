#pragma once
#include <string>

using namespace std;

class ReverseText
{
private:
  int num;
  string* words;

public:
  ReverseText();
  ~ReverseText();

  void inputText(string text);
  void outputReverseText();
};