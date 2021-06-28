#pragma once

class Fraction
{
private:
    int numerator;
    int denominator;
    int computeGCD(int x, int y);

public:
    Fraction(int n = 0, int d = 1);
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    int getNumerator();
    int getDenominator();
    void print();  

    Fraction operator+(Fraction & b);
    Fraction operator-(Fraction & b);
    Fraction operator*(Fraction & b);
    Fraction operator/(Fraction & b);
    bool operator==(Fraction & b);
    bool operator<(Fraction & b);
    bool operator>(Fraction & b);
};