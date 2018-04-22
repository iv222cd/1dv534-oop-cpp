#include "Fraction.h"

/******************************************************************************
* Fraction private member functions
******************************************************************************/

/**
* @brief Calculation the Greatest Common Divisor (GCD) of the numerator and the denominator of Fraction.
* Using Euclid's algorithm.
* @return GCD
*/
inline int Fraction::gcd()
{
   int a = _den > _nom ? _den : _nom; // Let a be the biggest of denominator and numerator
   int b = _den > _nom ? _nom : _den; // Let b be the smallest of denominator and numerator

   if (_nom == 0)
   {
      b = 1; // Avoid devision by zero by return gdc = 1 if numerator is zero.
   }
   else
   {
      int mod = a % b;

      while (mod != 0)
      {
         a = b;
         b = mod;
         mod = a % b;
      }
   }

   return b;
}

/**
* @brief Divide with GCD and make sure that the denominator is positive
*/
inline void Fraction::reduce()
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

/******************************************************************************
* Fraction public member functions
******************************************************************************/

/**
* @brief Overloading the + operator for fraction plus fraction. (fraction + fraction)
* The function adds two fraction objects, for example 2/3 + 3/2 = 13/6
* @return a new fraction that is the sum of the two arguments.
*/
Fraction Fraction::operator+(const Fraction f) const
{
   return Fraction(_nom * f._den + _den * f._nom, _den * f._den);
}

/**
* @brief Overloading the - operator for fraction minus fraction. (fraction - fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 - 3/2 = -5/6
* @return a new fraction that is the subtraction between the two arguments.
*/
Fraction Fraction::operator-(const Fraction f) const
{
   return Fraction(_nom * f._den - _den * f._nom, _den * f._den);
}

/**
* @brief Overloading the * operator for fraction times fraction. (fraction * fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 * 3/2 = 1
* @return a new fraction that is the multiple of the two arguments.
*/
Fraction Fraction::operator*(const Fraction f) const
{
   return Fraction(_nom * f._nom, _den * f._den);
}

/**
* @brief Overloading the / operator for fraction devided with fraction. (fraction / fraction)
* The function subtracts one fraction objects from antoher, for example 2/3 / 3/2 = 4/9
* @return a new fraction that is the devision between the two arguments.
*/
Fraction Fraction::operator/(const Fraction f) const
{
   return Fraction(_nom * f._den, _den * f._nom);
}

/**
* @brief Overloading the = operator for fraction assignement. (fraction = fraction)
* The function sets the value of one fraction the the current one.
* @return a copy of the assigned object.
*/
Fraction Fraction::operator=(const Fraction f) 
{
   _nom = f._nom;
   _den = f._den;
   return *this;
}

/**
* @brief Overloading the + operator for plus fraction. (+ fraction)
* @return a copy of the object.
*/
Fraction Fraction::operator+() const
{
   return *this;
}

/**
* @brief Overloading the - operator for minus fraction. (- fraction)
* @return a negative copy of the object.
*/
Fraction Fraction::operator-() const
{
   return Fraction(-1) * *this;
}

/**
* @brief Overloading the == operator coparing two fractions. (fraction == fraction)
* @return a negative copy of the object.
*/
bool Fraction::operator== (const Fraction f) const
{
   return ((_nom == f._nom) && (_den == f._den));
}

/**
* @brief Overloading the == operator coparing two fractions. (fraction == fraction)
* @return a negative copy of the object.
*/
bool Fraction::operator!= (const Fraction f) const
{
   return ((_nom != f._nom) || (_den != f._den));
}

/******************************************************************************
* Fraction friend functions
******************************************************************************/

/**
*@Note   The following functions are implemented as friend functions and not a member functions
* since the left hand argument is not of type Fraction.
*/

/**
* @brief Overloading the << operator. (stream << fraction)
* The function adds a representation of the Fraction object to the stream, for example 5/-3.
* @return stream object (same as input)
*/
ostream &operator<<(ostream &stream, Fraction f)
{
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
* @return stream object (same as input)
* Errors are returned with the internal state flags and set in the same manner as for istream::operator>> for basic types.
* Flag std::ios_base::failbit is set if the Fraction could not be read due to incorrect format.
*/
istream &operator>>(istream &stream, Fraction &f)
{
   // Read numerator
   stream >> f._nom;

   // Read '/' token.
   if (stream)
   {
      char div;
      stream >> std::ws; // Remove all white spaces before '/' token
      stream.get(div);

      if (div != '/')
      {
         stream.setstate(std::ios_base::failbit); // '/' token not found
      }
   }

   // Read denominator
   if (stream)
   {
      stream >> f._den;
   }

   // Fraction cleanup
   if (stream)
   {
      // Avoide division with zero by setting the fraction to 0.
      if (f._den == 0)
      {
         // TODO: throw std::overflow_error("Divide by zero exception");
         f._den = 1;
         f._nom = 0;
      }
      else
      {
         f.reduce(); // Devide with GCD
      }
   }
   return stream;
}

/**
* @brief Overloading the + operator for int plus fraction. (int + fraction)
* @return a new fraction that is the old fraction plus the int, for example 2 + 3/4 = 11/4
*/
Fraction operator+(const int i, const Fraction f)
{
   return Fraction(i) + f;
}

/**

* @brief Overloading the - operator for int minnus fraction. (int - fraction)
* @return a new fraction that is the int minus the fraction, for example 2 - 3/4 = 5/4
*/
Fraction operator-(const int i, const Fraction f)
{
   return Fraction(i) - f;
}

/**
* @brief Overloading the * operator for int times fraction. (int * fraction)
* @return a new fraction that is the int minus the fraction, for example 2 * 3/4 = 3/2
*/
Fraction operator*(const int i, const Fraction f)
{
   return Fraction(i) * f;
}

/**
* @brief Overloading the / operator for int devided with fraction. (int / fraction)
* @return a new fraction that is the int minus the fraction, for example 2 / 3/4 = 8/3
*/
Fraction operator/(const int i, const Fraction f)
{
   return Fraction(i) / f;
}
