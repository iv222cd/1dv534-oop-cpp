/**********************************************************************/
// File: miserable.cpp
// Summary: Practice file for Lab 1, Step 1, Part A.
//       The program performes the easy task of reading values from a
//       file (templog.txt) and make statistical calculations and present
//       these to the user, according to menu choise.
// Version: Version 1.1 - 2018-03-18
// Author:  Ingrid Wiklund/Anne Norling
// -------------------------------------------
// Log:  2018-03-18  Version 1.0 by Ingrid
//                   Copied the file from the homepage of Course 1DV534.
//                   The file is originally written by Anne Norling as
//                   an example of badly written code.
//       2018-03-18  Version 1.1 by Ingrid
//                   Refactoring the code to follow code standard in  
//                   Course 1DV534. Note that the functionality of the
//                   programm should still be the same.
/**********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::endl;
using std::setw;

int main()
{
   const string FILE_NAME_IN = "templog.txt";
   const int NUMBER_OF_VAULES = 24;
   int cnt;
   bool continueProg = true;
   double temperature[NUMBER_OF_VAULES];
   double sum, average;
   double max = 0, min = 0;
   char menuChoice;

   // Read values from file
   ifstream inFile(FILE_NAME_IN);

   for (cnt = 0; cnt < NUMBER_OF_VAULES; cnt++)
   {
      inFile >> temperature[cnt];
   }
   inFile.close();

   // Calculate average and min/max
   max = min = temperature[0];
   sum = 0.0;

   for (cnt = 1; cnt < NUMBER_OF_VAULES; cnt++)
   {
      sum += temperature[cnt];

      if (temperature[cnt] > max)
         max = temperature[cnt];

      if (temperature[cnt] < min)
         min = temperature[cnt];
   }
   average = sum / NUMBER_OF_VAULES;

   // Start output
   cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
   cin.get();

   while (continueProg)
   {
      system("cls");
      cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
      cin.get(menuChoice);
      cin.get();
      
      switch (menuChoice)
      {
      // Menu choice 1: Display temperature values
      case '1':
      {
         cout << "\nDisplaying the latest 24 temperature values:\n\n";

         for (cnt = 0; cnt < NUMBER_OF_VAULES; cnt++)
         {

            if (cnt % 6 == 0)
               cout << endl;
            cout << fixed << setprecision(2) << setw(8) << temperature[cnt];
         }
         break;
      }
      // Menu choice 2: View maximum and minimum temperatures
      case '2':
      {
         cout << "\nCalculating the maximum and minimum temperature...\n";
         cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
         cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
      }
      // Menu choice 3: View average temperature
      case '3':
      {
         cout << "\nCalculating average temperature...\n";
         cout << "\nAverage temperature: ";
         cout << fixed << setprecision(2) << average << " degrees Celcius\n";
         break;
      }
      // Menu choice 4: Quit
      case '4': // Fall through intendeed.
      default:
      {
         continueProg = false;
         cout << "\n\nTerminating the program.";
      }
      }
      cout << "\n\nPress Enter to continue:";
      cin.get();
   }

   return 0;
}