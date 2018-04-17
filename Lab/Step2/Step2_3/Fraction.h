#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
   int _nom; // Nominator
   int _den; // Denominator
   public:
   Fraction(): _nom(0), _den(1) {}
   Fraction(int nom): _nom(nom), _den(1) {}
   Fraction(int nom, int den): _nom(nom), _den(den) {} // TODO: Not set to zero

   int foo(int i);
   // Overloaded operators:
   Fraction operator+(Fraction frac); // frac + frac
   friend ostream &operator<<(ostream &stream, Fraction frac); // stream << frac
   friend istream &operator>>(istream &stream, Fraction frac); // stream >> frac
   friend Fraction operator+(int i, Fraction f); // int + frac
   Fraction operator*(Fraction f); // frac * frac
   Fraction operator-(Fraction f); // frac - frac
   Fraction operator/(Fraction f); // frac / frac
   Fraction operator=(Fraction f); // frac = frac
};


#endif /* FRACTION_H */