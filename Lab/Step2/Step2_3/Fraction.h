#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

// TODO: Comment.

class Fraction {
   int _nom; // Nominator
   int _den; // Denominator
public:
   Fraction() : _nom(0), _den(1) {}
   Fraction(int nom) : _nom(nom), _den(1) {}
   Fraction(int nom, int den) : _nom(nom), _den(den) {}

   // Overloaded operators
   // Friend function operators (where the rigth arg of the operator is not of type Fraction.)
   // TODO: write friend functions for all operators.

   friend ostream &operator<<(ostream &stream, Fraction frac); // stream << frac
   friend istream &operator>>(istream &stream, Fraction &frac); // stream >> frac
   friend Fraction operator+(int i, Fraction f); // int + frac
   // Member operators (where the rigth arg of the operator is of type Fraction.)
   Fraction operator+(Fraction frac); // frac + frac
   Fraction operator*(Fraction f); // frac * frac
   Fraction operator-(Fraction f); // frac - frac
   Fraction operator/(Fraction f); // frac / frac
   Fraction operator=(Fraction f); // frac = frac

   // TODO: overload operator ++, --, +=, -=, and logic operators
};


#endif /* FRACTION_H */