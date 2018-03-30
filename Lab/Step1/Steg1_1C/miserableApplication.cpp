/**********************************************************************/
// File: MiserableApplication.cpp
// Summary: 
// Version: Version 1.0 - 2013-03-25
// Author:  Ingrid Wiklund
// -------------------------------------------
// Log:  2004-08-23  Version 1.0 by Ingrid
//                   Created the file.
/**********************************************************************/
#include "Menu.h"
#include "Values.h"
#include "File.h"

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;


string APP_FILE_PATH = "templog.txt";
int NUM_OF_VALUES = 24;


/**
* @brief    Class for running the application miserable.
*/
class miserableApplication
{
   bool terminate;       // Set to true if the application should terminate.
   int status;           // Application status. Ok is 0.
   Menu menu;            // Menu object
   Values temperature;   // Object for temperature values
   File temperatureFile; // Object for reading temperature values
   int numOfValues;
public:
   miserableApplication();
   miserableApplication(string fileName, int numOfValues);
   ~miserableApplication();
   void displayAppInfo();
   void displayValues(Values buffer);
   void viewMaxAndMin(double max, double min);
   void viewAverage(double average);
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
miserableApplication::miserableApplication(string fileNameIn, int numOfValuesIn) : terminate(false), status(0), numOfValues(numOfValuesIn), temperatureFile(fileNameIn)
{
   cout << "\nConstruct miserableApplication overloaded";
}

/**
* @brief    Destructor
*/
miserableApplication::~miserableApplication()
{
   cout << "\nDestruct miserableApplication";

}

/**
* @brief    Run the application until the user terminates ut.
* 
* @return   Application termination status. Status ok if 0, error otherwise.
*/
int miserableApplication::run()
{

   // Display first info.
   displayAppInfo();

   // Read values
   cout << "\nReading logged values for processing and presentation...";
   cout << "\n";
   bool foo = temperatureFile.readValuesFromFile(&temperature, numOfValues);
   if (!foo)
   {
      terminate = true;
   }
   else
   {
      // Do calculations
      temperature.doCalulations();
      cout << "\nPress Enter for menu: ";
      cin.get();
   }

   while (!terminate)
   {
   // start loop
      menu.showMenu();
      menuCoice_e menuChoice = menu.getMenuChoice();
      switch (menuChoice)
      {
      case DISPLAY_VALUES:
         displayValues(temperature);
         break;
      case VIEW_MAX_AND_MIN:
         viewMaxAndMin(temperature.getMax(), temperature.getMin());
         break;
      case VIEW_AVERAGE:
         viewAverage(temperature.getAverage());
         break;
      case QUIT:
         cout << "\n\nTerminating the program.";
         terminate = true;
         break;
      }
      cout << "\n\nPress Enter to continue:";
      cin.get();
   }

   // end program

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
   //cout << "\ndisplayValues";
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
   //cout << "\nviewMaxAndMin";
   cout << "\nCalculating the maximum and minimum temperature...";
   cout << "\n";
   cout << "\nMaximum temperature: " << std::fixed << std::setprecision(2) << max << " degrees Celcius";
   cout << "\n";
   cout << "\nMinimum temperature: " << min << " degrees Celcius";
   cout << "\n";
}
void miserableApplication::viewAverage(double average)
{
   //cout << "\nviewAverage";
   cout << "\nCalculating average temperature...\n";
   cout << "\nAverage temperature: ";
   cout << std::fixed << std::setprecision(2) << average << " degrees Celcius";
   cout << "\n";
}

int main()
{
   const string APP_FILE_PATH = "templog.txt";
   const int NUM_OF_VALUES = 24;
   miserableApplication app(APP_FILE_PATH, NUM_OF_VALUES);

   return app.run();
}