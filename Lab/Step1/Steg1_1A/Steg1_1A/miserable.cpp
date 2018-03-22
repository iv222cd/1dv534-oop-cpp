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
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::endl;
using std::setw;

void showMenu();
char getMenuCoice();
bool readValuesFromFile(string fileName, double* values, int size);
void doCalulations(double* values, int size, double* min, double* max, double* average);

int main()
{
   const string FILE_NAME_IN = "templog.txt";
   const int NUMBER_OF_VAULES = 24;
   int cnt;
   bool continueProg = true;
   double temperature[NUMBER_OF_VAULES];
   double average;
   double max = 0, min = 0;
   char menuChoice = 'i';

   cout << "\n\nTemperature Statistics\n----------------------\n";

   while (continueProg)
   {
      switch (menuChoice)
      {
         // Init: Read values from file and calculate min, max and avg.
         case 'i':
         {
            cout << "\nReading logged values for processing and presentation...\n";

            if (readValuesFromFile(FILE_NAME_IN, temperature, NUMBER_OF_VAULES))
            {
               doCalulations(temperature, NUMBER_OF_VAULES, &min, &max, &average);
            }
            else
            {
               continueProg = false;
            }
            break;
         }
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
            break;
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
         case '4':
         {
            continueProg = false;
            break;
         }
         default:
         {
            cout << "\n'" << menuChoice << "' is not a valid menu choice. Please make a choice from the menu.\n";
            break;
         }
      }

      if (continueProg)
      {
         if (menuChoice == 'i')
         {
            cout << "\nPress Enter for menu: ";
         }
         else
         {
            cout << "\n\nPress Enter to continue:";
         }
         cin.ignore(INT_MAX, '\n'); // Remove any trailing chars that the user migth have written.

         showMenu();
         menuChoice = getMenuCoice();
      }
   }

   cout << "\n\nTerminating the program.";
   cout << "\n\nPress Enter to continue:";
   cin.ignore(INT_MAX, '\n'); // Remove any trailing chars that the user migth have written.

   return 0;
}

/**
* @brief  Clear consol and print program menu.
*/
void showMenu()
{
   system("cls");
   cout << "\n";
   cout << "\nMENU\n----\n";
   cout << "\n1.Display temperature values";
   cout << "\n2.View maximum and minimum temperatures";
   cout << "\n3.View average temperature";
   cout << "\n4.Quit\n";
}

/**
* @brief  Get the menu choice of the user from consol input.
* 
* If an unvalid char is given, the user will be promted again. All other chars until new line will be ignored.
*
* @return  Char number between '1' and '4' representing the users choise.
*/
char getMenuCoice()
{
   char menuChoice;
   bool valid = false;
   
   cout << "\nMake your choice : ";
   
   while (!valid)
   {
      cin.get(menuChoice);
      cin.ignore(INT_MAX, '\n'); // Remove any trailing chars that the user migth have written.
      if (menuChoice < '1' || menuChoice > '4')
      {
         cout << "\n'" << menuChoice << "' is not a valid menu choice. Please make a choice from the menu.\n";
      }
      else
      {
         valid = true;
      }
   }
   return menuChoice;
}

/**
* @brief  Read blank separated double values from a file.
*
* @param fileName    Input file with values
* @param values      Pointer to array where values can be stored. Needs to be of at least size.
* @param size        Number of values to read. Length of array values.
* @return            true if the reading suceeded, false otherwise.
*/
bool readValuesFromFile(string fileName, double* values, int size)
{
   bool status = true;
   // Read values from file
   ifstream inFile(fileName);

   if (inFile.is_open())
   {
      for (int cnt = 0; cnt < size; cnt++)
      {
         inFile >> values[cnt];
         if (!inFile)
         {
            cout << "Could not read values from file " << fileName;
            cin.get();
            status = false;
            break;
         }
      }
      inFile.close();
   }
   else
   {
      cout << "Could not open file " << fileName;
      cin.get();
      status = false;
   }
   return status;
}

/**
* @brief  Calculate min, max and average from an double array
*
* @param values      Pointer to input array with values.
* @param size        Length of array values.
* @param min         Pointer to parameter for min result output.
* @param max         Pointer to parameter for max result output.
* @param average     Pointer to parameter for average result output.
*/
void doCalulations(double* values, int size, double* min, double* max, double* average)
{
   // Calculate average and min/max
   *max = *min = values[0];
   double sum = 0.0;

   for (int cnt = 1; cnt < size; cnt++)
   {
      sum += values[cnt];

      if (values[cnt] > *max)
         *max = values[cnt];

      if (values[cnt] < *min)
         *min = values[cnt];
   }
   *average = sum / size;
}