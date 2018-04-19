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
   if ((_den * _gcd) < 0)
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
ostream &operator<<(ostream &stream, Fraction f)
{
   // Devide with GCD before presenting the fraction
   f.reduce();

   if (f._den != 1)
   {
      stream << f._nom << "/" << f._den;
   }
   else
   {
      // f is a integer, represent with the numerator
      stream << f._nom;
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
istream &operator>>(istream &stream, Fraction &f)
{
   stream >> f._nom;
   stream.ignore(INT_MAX,'/'); // Remove the '/' char
   stream >> f._den;
   //TODO: Error handling.
   //if (!stream) ....
   // Maby set the stream fail bit?
   //TODO: What happens if the user does no give a '/' token?.
   //stream.setstate(std::istream::badbit);
   return stream;
}

/**
* @brief Overloading the + operator for int plus fraction. (int + fraction)
* The function is implemented as a friend function and not a member function
* since the left hand argument is not of type Fraction.
* @return a new fraction that is the old fraction plus the int, for example 2 + 3/4 = 11/4
*/
Fraction operator+(int i, Fraction f)
{
   return Fraction(i) + f;
}

/**

* @brief Overloading the - operator for int minnus fraction. (int - fraction)
* The function is implemented as a friend function and not a member function
* since the left hand argument is not of type Fraction.
* @return a new fraction that is the int minus the fraction, for example 2 - 3/4 = 5/4
*/
Fraction operator-(int i, Fraction f)
{
   return Fraction(i) - f;
}

/**
* @brief Overloading the * operator for int times fraction. (int * fraction)
* The function is implemented as a friend function and not a member function
* since the left hand argument is not of type Fraction.
* @return a new fraction that is the int minus the fraction, for example 2 * 3/4 = 3/2
*/
Fraction operator*(int i, Fraction f)
{
   return Fraction(i) * f;
}

/**
* @brief Overloading the / operator for int devided with fraction. (int / fraction)
* The function is implemented as a friend function and not a member function
* since the left hand argument is not of type Fraction.
* @return a new fraction that is the int minus the fraction, for example 2 / 3/4 = 8/3
*/
Fraction operator/(int i, Fraction f)
{
   return Fraction(i) / f;
}

/**
* @brief Overloading the + operator for fraction plus fraction. (fraction + fraction)
* The function adds two fraction objects, for example 2/3 + 3/2 = 13/6
* @return a new fraction that is the sum of the two arguments.
*/
Fraction Fraction::operator+(Fraction f)
{
   Fraction result;

   result._nom = _nom * f._den + _den * f._nom;
   result._den = _den * f._den;
   return result;
}

/**
* @brief Overloading the - operator for fraction minus fraction. (fraction - fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 - 3/2 = -5/6
* @return a new fraction that is the subtraction between the two arguments.
*/
Fraction Fraction::operator-(Fraction f)
{
   Fraction result;

   result._nom = _nom * f._den - _den * f._nom;
   result._den = _den * f._den;
   return result;
}

/**
* @brief Overloading the * operator for fraction times fraction. (fraction * fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 * 3/2 = 1
* @return a new fraction that is the multiple of the two arguments.
*/
Fraction Fraction::operator*(Fraction f)
{
   Fraction result;

   result._nom = _nom * f._nom;
   result._den = _den * f._den;
   return result;
}

/**
* @brief Overloading the / operator for fraction devided with fraction. (fraction / fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 / 3/2 = 4/9
* @return a new fraction that is the devision between the two arguments.
*/
Fraction Fraction::operator/(Fraction f)
{
   Fraction result;

   result._nom = _nom * f._den;
   result._den = _den * f._nom;
   return result;
}

/**
* @brief Overloading the = operator for fraction assignement. (fraction = fraction)
* The function sets the value of one fraction the the current one.
* @return a copy of the assigned object.
*/
Fraction Fraction::operator=(Fraction f)
{
   _nom = f._nom;
   _den = f._den;
   return *this;
}
