#include "Fraction.h"

// TODO: Not set denominator to zero
// TODO: Add gcn-functionality.
// TODO: Comment.


ostream &operator<<(ostream &stream, Fraction frac)
{
   stream << frac._nom << "/" << frac._den;
   return stream;
}

istream &operator>>(istream &stream, Fraction frac)
{
   // TODO: implement correctly.
   stream >> frac._nom;
   stream.get(); // '/'
   stream >> frac._den;
   return stream;
}

Fraction operator+(int i, Fraction f)
{
   Fraction result;

   result._nom = i * f._den + f._nom;
   result._den = f._den;
   return result;
}

Fraction Fraction::operator+(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._den + _den * frac._nom;
   result._den = _den * frac._den;
   return result;
}

Fraction Fraction::operator-(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._den - _den * frac._nom;
   result._den = _den * frac._den;
   return result;
}

Fraction Fraction::operator*(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._nom;
   result._den = _den * frac._den;
   return result;
}

Fraction Fraction::operator/(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._den;
   result._den = _den * frac._nom;
   return result;
}

Fraction Fraction::operator=(Fraction frac)
{
   _nom = frac._nom;
   _den = frac._den;
   return *this;
}
