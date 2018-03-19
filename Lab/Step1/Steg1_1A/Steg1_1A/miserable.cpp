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
   int cnt, continueProg = 1;
   double temperature, sum, average;
   char menuChoise;

   cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
   cin.get();

   while (continueProg)
   {
      system("cls");
      cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";
      cin.get(menuChoise);
      cin.get();
      
      if (menuChoise == '1')
      {
         // Menu choise 1: Display temperature values
         cout << "\nDisplaying the latest 24 temperature values:\n\n";
         ifstream inFile(FILE_NAME_IN);

         for (cnt = 0; cnt < NUMBER_OF_VAULES; cnt++)
         {

            if (cnt % 6 == 0)
               cout << endl;
            inFile >> temperature;
            cout << fixed << setprecision(2) << setw(8) << temperature;
         }
         inFile.close();
      }
      else if (menuChoise == '2')
      {
         // Menu choise 2: View maximum and minimum temperatures
         cout << "\nCalculating the maximum and minimum temperature...\n";
         double max = 0, min = 0;
         ifstream inFile(FILE_NAME_IN);
         inFile >> temperature;
         max = min = temperature;

         for (cnt = 1; cnt < NUMBER_OF_VAULES; cnt++)
         {
            inFile >> temperature;

            if (temperature > max)
               max = temperature;

            if (temperature < min)
               min = temperature;
         }
         inFile.close();
         cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
         cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
      }
      else if (menuChoise == '3')
      {
         // Menu choise 3: View average temperature
         cout << "\nCalculating average temperature...\n";
         sum = 0.0;
         ifstream inFile(FILE_NAME_IN);

         for (cnt = 0; cnt < NUMBER_OF_VAULES; cnt++)
         {
            inFile >> temperature;
            sum += temperature;
         }
         inFile.close();
         average = sum / NUMBER_OF_VAULES;
         cout << "\nAverage temperature: ";
         cout << fixed << setprecision(2) << average << " degrees Celcius\n";
      }
      else
      {
         // Menu choise 4: Quit
         continueProg = 0;
         cout << "\n\nTerminating the program.";
      }
      cout << "\n\nPress Enter to continue:";
      cin.get();
   }

   return 0;
}