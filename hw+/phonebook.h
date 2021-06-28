#pragma once
#include <string>

using namespace std;

class Person
{
private:
  string name;
  string phone_number;

public:
  Person();
  ~Person();
  string getName();
  void setName(string name);
  string getPhoneNumber();
  void setPhoneNumber(string phone_number);
};

class PhoneBook
{
private:
  int num;
  Person* people;

public:
  PhoneBook();
  ~PhoneBook();

  void inputPhoneBook();
  void findPhoneBook();
};