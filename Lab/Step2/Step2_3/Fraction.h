#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

/**
* @brief Class for storing a fraction of integears (a rational number)
* The following operators are overloaded in this class:
*  Fraction = Fraction
*  Fraction + Fraction
*  Fraction - Fraction
*  Fraction * Fraction
*  Fraction / Fraction
*  int + Fraction
*  int - Fraction
*  int * Fraction
*  int / Fraction
*  ostram << Fraction
*  istream >> Fraction

* @Note Operators on the form
*  Fraction operator int
* doesn't need to be overloaded since the int is turned into a Fraction object
* with the constructor Fraction(int).
*/
class Fraction {
   int _nom; // Nominator
   int _den; // Denominator
   int gcd();
public:
   Fraction() : _nom(0), _den(1) {}
   Fraction(int nom) : _nom(nom), _den(1) {}
   Fraction(int nom, int den) : _nom(nom), _den(den) {}

   // Overloaded operators
   // TODO: write friend functions for all operators.
   // Friend function operators (where the rigth arg of the operator is not of type Fraction.)
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