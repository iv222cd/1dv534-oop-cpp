/**********************************************************************/
// File: MiserableApplication.cpp
// Summary: 
// Version: Version 1.0 - 2013-03-25
// Author:  Ingrid Wiklund
// -------------------------------------------
// Log:  2004-08-23  Version 1.0 by Ingrid
//                   Created the file.
// Log:  2004-08-30  Version 1.1 by Ingrid
//                   Implemented mayor part of application.
/**********************************************************************/
#include "Menu.h"
#include "Values.h"

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

/**
* @brief    Class for running the application miserable.
*/
class miserableApplication
{
   bool terminate;       // Set to true if the application should terminate.
   int status;           // Application status. Ok is 0.
   Menu menu;            // Menu object
   Values temperature;   // Object for temperature values
public:
   miserableApplication();
   miserableApplication(string fileName, int numOfValues);
   ~miserableApplication();
   void displayAppInfo();
   void displayValues(Values buffer);
   void viewMaxAndMin(double max, double min);
   void viewAverage(double average);
   void waitForUser();
   int run();
};

/**
* @brief    Constructor
*/
miserableApplication::miserableApplication()
{
   cout << "\nConstruct miserableApplication";
}

/**
* @brief    Constructor
*/
miserableApplication::miserableApplication(string fileNameIn, int numOfValues) : terminate(false), status(0), temperature(fileNameIn, numOfValues)
{
   cout << "\n--Construct miserableApplication overloaded";
}

/**
* @brief    Destructor
*/
miserableApplication::~miserableApplication()
{
   cout << "\n--Destruct miserableApplication";
}

/**
* @brief    Run the application until the user terminates ut.
* 
* @return   Application termination status. Status ok if 0, error otherwise.
*/
int miserableApplication::run()
{
   bool first_run = true;
   // Display first info.
   displayAppInfo();
   // Read values
   cout << "\nReading logged values for processing and presentation...";
   cout << "\n";
   bool foo = temperature.readValuesFromFile();

   if (!foo)
   {
      cout << "\nCould not read values from file " << temperature.getInFileName();
      cout << "\n";
      cout << "\nTerminating the program.";
      terminate = true;
   }
   else
   {
      // Do calculations
      temperature.doCalulations();
   }

   while (!terminate)
   {
      if (first_run)
      {
         cout << "\nPress Enter for menu: ";
         cin.ignore(INT_MAX, '\n');
      }
      else
      {
         waitForUser();
      }
      menu.showMenu();

      switch (menu.getMenuChoice())
      {
      case Menu::DISPLAY_VALUES:
         displayValues(temperature);
         break;
      case Menu::VIEW_MAX_AND_MIN:
         viewMaxAndMin(temperature.getMax(), temperature.getMin());
         break;
      case Menu::VIEW_AVERAGE:
         viewAverage(temperature.getAverage());
         break;
      case Menu::QUIT:
         cout << "\n";
         cout << "\nTerminating the program.";
         terminate = true;
         break;
      }
   }
   waitForUser();
   return status;
}


void miserableApplication::displayAppInfo()
{
   cout << "\n";
   cout << "\nTemperature Statistics";
   cout << "\n----------------------";
   cout << "\n";
}
void miserableApplication::displayValues(Values buffer)
{
   cout << "\nDisplaying the latest 24 temperature values:";
   cout << "\n";
   cout << "\n";
   for (int i = 0; i < buffer.getNumberOfValues(); i++)
   {
      if (i % 6 == 0)
         cout << "\n";
      cout << std::fixed << std::setprecision(2) << std::setw(8) << buffer.getValue(i);
   }
}
void miserableApplication::viewMaxAndMin(double max, double min)
{
   cout << "\nCalculating the maximum and minimum temperature...";
   cout << "\n";
   cout << "\nMaximum temperature: " << std::fixed << std::setprecision(2) << max << " degrees Celcius";
   cout << "\n";
   cout << "\nMinimum temperature: " << min << " degrees Celcius";
   cout << "\n";
}
void miserableApplication::viewAverage(double average)
{
   cout << "\nCalculating average temperature...\n";
   cout << "\nAverage temperature: ";
   cout << "\nMaximum temperature: " << std::fixed << std::setprecision(2) << average << " degrees Celcius";
   cout << "\n";
}


void miserableApplication::waitForUser()
{
   cout << "\n";
   cout << "\nPress Enter to continue:";
   cin.ignore(INT_MAX, '\n');
}

int main()
{
   const string APP_FILE_PATH = "templog.txt";
   const int NUM_OF_VALUES = 24;
   miserableApplication app(APP_FILE_PATH, NUM_OF_VALUES);

   return app.run();
}