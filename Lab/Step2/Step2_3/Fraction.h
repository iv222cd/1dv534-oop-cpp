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
*  + Fraction
*  - Fraction

* @Note Operators on the form
*  Fraction operator int
* doesn't need to be overloaded since the int is turned into a Fraction object
* with the constructor Fraction(int).
*/
class Fraction {
   int _nom; // Nominator
   int _den; // Denominator
   int gcd();
   void reduce();
public:
   Fraction() : _nom(0), _den(1) {}
   Fraction(int nom) : _nom(nom), _den(1) {}
   Fraction(int nom, int den) : _nom(nom), _den(den) {}

   // Overloaded operators
   // TODO: write friend functions for all operators.
   // Friend function operators (where the rigth arg of the operator is not of type Fraction.)
   friend ostream &operator<<(ostream &stream, const Fraction f); // stream << frac
   friend istream &operator>>(istream &stream, const Fraction &f); // stream >> frac
   friend Fraction operator+(const int i, const Fraction f); // int + frac
   friend Fraction operator-(const int i, const Fraction f); // int - frac
   friend Fraction operator*(const int i, const Fraction f); // int * frac
   friend Fraction operator/(const int i, const Fraction f); // int / frac
   // Member operators (where the rigth arg of the operator is of type Fraction.)
   Fraction operator=(const Fraction f); // frac = frac
   Fraction operator+(const Fraction f) const; // frac + frac
   Fraction operator-(const Fraction f) const; // frac - frac
   Fraction operator*(const Fraction f) const; // frac * frac
   Fraction operator/(const Fraction f) const; // frac / frac
   Fraction operator+() const; // +frac
   Fraction operator-() const; // -frac

   // TODO: overload operator ++, --, +=, -=, and logic operators
};

class FractionError {

};

#endif /* FRACTION_H */