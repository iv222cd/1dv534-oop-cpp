/*************************************************************************/
// File:   Test2_3.cpp
// Summary:   Test file for Lab 3, Step 2
//         The program will test functionality for class Fraction, 
//         which is aimed to represent and handle fractional values.
//         If defined according to requirements in given specification, 
//         the result of execution is expected to present outputs
//         like examples suggested in test code comments.
//         NO CHANGES of predefined code are allowed, except ...
//         1. code needed to handle exceptions, if solving optional task
//         2. code aiming to provide the program with quality enhancing 
//         details (e.g. an improved, user friendly interface). Such 
//         changes should be well motivated in commenting to code.
// Version:  Version 1.4 - 2013-04-22
// Author:   Anne Norling
// ------------------------------------------
// Log:    2003-08-25   Created the file. Anne
//         2013-04-08   Uppdate  Version 1.1 by Anne. 
//                  Converted to English and VS 2012
//         2015-03-06   Revised by Anne. Converted to VS 2013
//         2018-04-05   Code tested for VS 2017, by Anne
//         2018-04-22   Added some cin error handling, by Ingrid Wiklund
//         2018-04-22   Encapsulated the program in a try-catch statement, by Ingrid Wiklund
//         2018-04-22   Added more test for better test coverage, by Ingrid Wiklund
//                      Using exception for testing with the simple TestFailException class.
//         2018-04-22   Testing that a overflow exception is thrown when dividing with zero.
//         2018-05-27   Adding a catch for devision with zero.
//                      Also throwing TestFailException on inccorect input format for fractions intead of just clearing the error.
//                      This is to give more informative output to user at input errors.
//         2018-05-27   Replacing cin in Ingrid's testpart with a stringstream,
//                      so less manual testing is required.
//         2018-05-27   Replacing std::exception with the less generic std::overflow_error in tests.
//         2018-05-27   Adding test on bad input format.
/*************************************************************************/

#include <iostream>
#include <sstream>
#include "Fraction.h"
#include "TestFailException.h"

using std::endl;
using std::cin;
using std::cout;

class Application
{
   void testEqual(Fraction expected, Fraction actual);
public:
   int run();
};

/**
* @brief    Compare expected and actual. Throw exception "TestFailException" if not equal.
*/
void Application::testEqual(Fraction expected, Fraction actual)
{
   if (expected != actual)
   {
      stringstream s;
      s << "Test Failed! Expected " << expected << ", was " << actual << endl;
      throw TestFailException(s.str());
   }
}

int Application::run()
{
   Fraction f1(3, 2);   // numerator=3, denominator=2 ("täljare"=3, "nämnare"=2)
   Fraction f2(10);   // numerator=10, denominator=1
   Fraction result;

   // Testing class Fraction with predefined values
   cout << "Test 1:" << endl;
   cout << "(1 + 3/2) * (10 - 3) = ";

   cout << (1 + f1) * (f2 - 3) << endl << endl;   // Should print "35/2"

   // Will test arithmetic operations between two fractions, entered by the user
   cout << "Test 2:" << endl;
   cout << "Input two fractions as example: 2/-3 5/6 (separated by whitespace):" << endl;
   cin >> f1 >> f2;
   // ** This section by Ingrid Wiklund ****************
   // If error in input
   if (!cin)
   {
      throw TestFailException("Inccorect input from the user!");
   }
   // ** End section by Ingrid Wiklund ****************

   result = f1 + f2;   
   // Following should output "2/-3 + 5/6 = 1/6" if test case examples was used
   cout << endl << f1 << " + " << f2 << " = " << result << endl;

   result = f1 - f2;
   // Following should output "2/-3 - 5/6 = -3/2" if test case examples was used
   cout << endl << f1 << " - " << f2 << " = " << result << endl;

   result = f1 * f2;
   // Following should output "2/-3 * 5/6 = -5/9" if test case examples was used   
   cout << endl << f1 << " * " << f2 << " = " << result << endl;

   result = f1 / f2;      
   // Following should output "2/-3 / 5/6 = -4/5" if test case examples was used
   cout << endl << f1 << " / " << f2 << " = " << result << endl;


   // ** This section by Ingrid Wiklund ****************
   // Test int _ Fraction
   cout << "================================" << endl;
   cout << "Start of tests written by Ingrid" << endl;
   cout << "================================" << endl;

   int i = 3;
   Fraction f3(3, -2);
   Fraction f4(2, 3);
   Fraction expected;

   // result = int _ fraction
   expected = Fraction(3, 2);
   result = i + f3;
   cout << endl << i << " + " << f3 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(9, 2);
   result = i - f3;
   cout << endl << i << " - " << f3 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(-9, 2);
   result = i * f3;
   cout << endl << i << " * " << f3 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(-2, 1);
   result = i / f3;
   cout << endl << i << " / " << f3 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   // result = _ fraction
   expected = Fraction(-3, 2);
   result = +f3;
   cout << endl << result << " =+ " << f3 << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(3, 2);
   result = -f3;
   cout << endl << result << " =- " << f3 << " =? " << expected << endl;
   testEqual(expected, result);

   // result = fraction _ fraction
   expected = Fraction(-5, 6);
   result = f3 + f4;
   cout << endl << f3 << " + " << f4 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(-13, 6);
   result = f3 - f4;
   cout << endl << f3 << " - " << f4 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(-1);
   result = f3 * f4;
   cout << endl << f3 << " * " << f4 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   expected = Fraction(-9, 4);
   result = f3 / f4;
   cout << endl << f3 << " / " << f4 << " = " << result << " =? " << expected << endl;
   testEqual(expected, result);

   // Test division by zero (should throw exception)
   try
   {
      cout << endl << "1/0 -> overflow_error" << endl;
      Fraction(1, 0); // Devision with zero.
      throw TestFailException("Test Failed: No exception when dividing with zero");
   }
   catch (const std::overflow_error)
   {
      // All is well. Test passed. Continue...
   }

   try
   {
      f4 = Fraction(0);
      cout << endl << f3 << " / " << f4 << " -> overflow_error" << endl;
      result = f3 / f4;
      throw TestFailException("Test Failed: No exception when dividing with zero");
   }
   catch (const std::overflow_error)
   {
      // All is well. Test passed. Continue...
   }

   try
   {
      std::stringstream ss("1/0");
      cout << endl << ss.str() << " >> Fraction -> overflow_error" << endl;
      ss >> f3;
      throw TestFailException("Test Failed: No exception when dividing with zero");
   }
   catch (const std::overflow_error)
   {
      // All is well. Test passed. Continue...
   }

   std::stringstream ss("x/y");
   cout << endl << ss.str() << " >> Fraction -> stream.fail() = true" << endl;
   ss >> f3;
   if (!ss.fail())
   {
      throw TestFailException("Test Failed: Stream did not fail on bad input format.");
   }

   // ** End section by Ingrid Wiklund ****************

   cin.get();
   return 0;
}

int main()
{
   Application myApp;
   int returnValue = -1;
   try
   {
      returnValue = myApp.run();
      cout << endl << "All testes passed" << endl;
      cin.get();
   }
   catch (TestFailException &e)
   {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << endl << "Test failed" << endl;
      cout << e.getMessage() << endl;
      cout << "Exiting testprogram" << endl;
      cin.get();
   }
   catch (std::overflow_error)
   {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Division by zero!" << endl;
      cout << "Exiting testprogram" << endl;
      cin.get();
   }
   catch (...)
   {
      cout << endl << "Program stopped du to an unknow error" << endl;
      cin.get();
      throw;
   }
   return returnValue;
}