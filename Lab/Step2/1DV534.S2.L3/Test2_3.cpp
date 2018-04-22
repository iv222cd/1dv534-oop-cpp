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
// Version:  Version 1.2 - 2013-04-22
// Author:   Anne Norling
// ------------------------------------------
// Log:    2003-08-25   Created the file. Anne
//         2013-04-08   Uppdate  Version 1.1 by Anne. 
//                  Converted to English and VS 2012
//         2015-03-06   Revised by Anne. Converted to VS 2013
//         2018-04-05   Code tested for VS 2017, by Anne
//         2018-04-22   Added some cin error handling, by Ingrid Wiklund
/*************************************************************************/

#include <iostream>
#include "Fraction.h"
using std::endl;
using std::cin;
using std::cout;

class Application
{
public:
   int run();
};

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
      cin.clear();
      cin.ignore(INT_MAX, '\n');
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

   cin.get();
   return 0;
}

int main()
{
   Application myApp;
   return myApp.run();
}