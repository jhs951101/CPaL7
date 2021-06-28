#pragma once

class Circle
{
private:
  double radius;

public:
  Circle();
  ~Circle();

  double getRadius();
  void setRadius(double r);
  double calculateArea();
};

class CircleManager
{
private:
  int num;
  Circle* circles;

public:
  CircleManager();
  ~CircleManager();

  void inputCircles();
  void outputResults();
};
