/**********************************************************************/
// File: MiserableApplication.cpp
// Summary: Reads a number of temperature values from file and print it to CLI
//          according to user input.
// Version: Version 1.2 - 2018-04-04
// Author:  Ingrid Wiklund
// -------------------------------------------
// Log:  2018-03-23  Version 1.0 by Ingrid
//                   Created the file.
// Log:  2018-03-30  Version 1.1 by Ingrid
//                   Implemented the application according to 
//                   Class_Diagram.png and Sequence_Diagram.png.
// Log:  2018-04-04  Version 1.2 by Ingrid
//                   Renaming main file to follow class name. 
//                   Added missing call to system(cls) when showing menu.
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
class TemperatureApp
{
   bool quit;            // Set to true if the application should terminate.
   int status;           // Application status. Ok is 0.
   Menu menu;            // Menu object
   Values temperature;   // Object for temperature values
   void displayAppInfo();
   void displayValues(Values buffer);
   void viewMaxAndMin(double max, double min);
   void viewAverage(double average);
   void waitForUser(bool waitForMenu);
   void viewQuitMessage();
public:
   TemperatureApp();
   TemperatureApp(string fileName, int numOfValues);
   ~TemperatureApp();
   int run();
};

/**
* @brief    Constructor
*/
TemperatureApp::TemperatureApp()
{
}

/**
* @brief    Parameterized Constructor
*/
TemperatureApp::TemperatureApp(string fileNameIn, int numOfValues) : quit(false), status(0), temperature(fileNameIn, numOfValues)
{
}

/**
* @brief    Destructor
*/
TemperatureApp::~TemperatureApp()
{
}

/**
* @brief    Run the application until the user terminates ut.
* 
* @return   Application termination status. 0 if status ok if 0.
*/
int TemperatureApp::run()
{
   bool first_run = true;

   // Display first info.
   displayAppInfo();
   // Read values
   cout << "\nReading logged values for processing and presentation...";

   if (temperature.readValuesFromFile())
   {
      temperature.doCalulations();
   }
   else
   {
      cout << "\nCould not read values from file " << temperature.getInFileName();
      status = -1;
      viewQuitMessage();
      quit = true;
   }

   while (!quit)
   {
      waitForUser(first_run);
      first_run = false;
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
         viewQuitMessage();
         quit = true;
         break;
      }
   }

   waitForUser(false);
   return status;
}

/**
* @brief    Display information about the application to CLI
*/
void TemperatureApp::displayAppInfo()
{
   cout << "\n";
   cout << "\nTemperature Statistics";
   cout << "\n----------------------";
   cout << "\n";
}

/**
* @brief    Display temperature values in buffer to CLI
*/
void TemperatureApp::displayValues(Values buffer)
{
   cout << "\nDisplaying the latest " << buffer.getNumberOfValues() << " temperature values:";
   cout << "\n";
   cout << "\n";
   for (int i = 0; i < buffer.getNumberOfValues(); i++)
   {
      if (i % 6 == 0)
         cout << "\n";
      cout << std::fixed << std::setprecision(2) << std::setw(8) << buffer.getValue(i);
   }
}

/**
* @brief    Display min and max values of buffer to CLI
*/
void TemperatureApp::viewMaxAndMin(double max, double min)
{
   cout << "\nCalculating the maximum and minimum temperature...";
   cout << "\n";
   cout << "\nMaximum temperature: " << std::fixed << std::setprecision(2) << max << " degrees Celcius";
   cout << "\n";
   cout << "\nMinimum temperature: " << min << " degrees Celcius";
   cout << "\n";
}

/**
* @brief    Display average value of buffer to CLI
*/
void TemperatureApp::viewAverage(double average)
{
   cout << "\nCalculating average temperature...";
   cout << "\n";
   cout << "\nMaximum temperature: " << std::fixed << std::setprecision(2) << average << " degrees Celcius";
   cout << "\n";
}

/**
* @brief    Display message to  CLI that user should give input before continuing program
* @param    waitForMenu    set to true to display menu waiting option.
*                          set to false otherwise and a more generec message will follow
*/
void TemperatureApp::waitForUser(bool waitForMenu)
{
   cout << "\n";
   if (waitForMenu)
   {
      cout << "\nPress Enter for menu: ";
   }
   else
   {
      cout << "\nPress Enter to continue:";
   }
   cin.ignore(INT_MAX, '\n');
}

/**
* @brief    Display quit message to CLI
*/
void TemperatureApp::viewQuitMessage()
{
   cout << "\n";
   cout << "\nTerminating the program.";
}

int main()
{
   const string APP_FILE_PATH = "templog.txt";
   const int NUM_OF_VALUES = 24;
   TemperatureApp app(APP_FILE_PATH, NUM_OF_VALUES);

   return app.run();
}