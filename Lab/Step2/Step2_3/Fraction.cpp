#include "Fraction.h"

// TODO: Not set denominator to zero
// TODO: Protect inargs with const?

/**
* @brief Calculation the Greatest Common Divisor (GCD) of the numerator and the denominator of Fraction.
* Using Euclid's algorithm.
* @return GCD
*/
int Fraction::gcd()
{
   int a = _den > _nom ? _den : _nom; // Let a be the biggest of denominator and numerator
   int b = _den > _nom ? _nom : _den; // Let b be the smallest of denominator and numerator
   int mod = a % b;

   while (mod != 0)
   {
      a = b;
      b = mod;
      mod = a % b;
   }

   return b;
}

/**
* @brief Divide with GCD and make sure that the denominator is positive
*/
void Fraction::reduce()
{
   int _gcd = gcd();

   // Always let the denominator be positive.
   // If the fraction is negateive let that be represented by a negative numerator.
   if ((_den < 0) && (_gcd > 0))
   {
      _gcd *= -1;
   }

   _den /= _gcd;
   _nom /= _gcd;
}

/**
* @brief Overloading the << operator. (stream << fraction)
* The function adds a representation of the Fraction object to the stream, for example 5/-3.
* The function is implemented as a friend function and not a member function
* since the left hand argument is not of type Fraction.
* @return stream object (same as input)
*/
ostream &operator<<(ostream &stream, Fraction frac)
{
   // Devide with GCD before presenting the fraction
   frac.reduce();

   if (frac._den != 1)
   {
      stream << frac._nom << "/" << frac._den;
   }
   else
   {
      // frac is a integer, represent with the numerator
      stream << frac._nom;
   }

   return stream;
}

/**
* @brief Overloading the >> operator. (stream << fraction)
* The fuction extracts a representation from the stream, for example '5/-3'.
* The function is implemented as a friend function and not a member function
* since the left hand argument is not of type Fraction.
* @return stream object (same as input)
*/
istream &operator>>(istream &stream, Fraction &frac)
{
   stream >> frac._nom;
   stream.ignore(INT_MAX,'/'); // Remove the '/' char
   stream >> frac._den;
   //TODO: Error handling.
   //if (!stream) ....
   // Maby set the stream fail bit?
   //TODO: What happens if the user does no give a '/' token?.
   //stream.setstate(std::istream::badbit);
   return stream;
}

/**
* @brief Overloading the + operator for int plus fraction. (int + fraction)
* The function is implemented as a firend functions and not a member function
* since the left hand argument is not of type Fraction.
* @return a new fraction that is the old fraction plus the int, for example 2 + 3/4 = 11/4
*/
Fraction operator+(int i, Fraction fraction)
{
   Fraction result;

   result._nom = i * fraction._den + fraction._nom;
   result._den = fraction._den;
   return result;
}

/**
* @brief Overloading the + operator for fraction plus fraction. (fraction + fraction)
* The function adds two fraction objects, for example 2/3 + 3/2 = 13/6
* @return a new fraction that is the sum of the two arguments.
*/
Fraction Fraction::operator+(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._den + _den * frac._nom;
   result._den = _den * frac._den;
   return result;
}

/**
* @brief Overloading the - operator for fraction minus fraction. (fraction - fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 - 3/2 = -5/6
* @return a new fraction that is the subtraction between the two arguments.
*/
Fraction Fraction::operator-(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._den - _den * frac._nom;
   result._den = _den * frac._den;
   return result;
}

/**
* @brief Overloading the * operator for fraction times fraction. (fraction * fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 * 3/2 = 1
* @return a new fraction that is the multiple of the two arguments.
*/
Fraction Fraction::operator*(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._nom;
   result._den = _den * frac._den;
   return result;
}

/**
* @brief Overloading the / operator for fraction devided with fraction. (fraction / fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 / 3/2 = 4/9
* @return a new fraction that is the devision between the two arguments.
*/
Fraction Fraction::operator/(Fraction frac)
{
   Fraction result;

   result._nom = _nom * frac._den;
   result._den = _den * frac._nom;
   return result;
}

/**
* @brief Overloading the = operator for fraction assignement. (fraction = fraction)
* The function sets the value of one fraction the the current one.
* @return a copy of the assigned object.
*/
Fraction Fraction::operator=(Fraction frac)
{
   _nom = frac._nom;
   _den = frac._den;
   return *this;
}
