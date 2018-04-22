/**********************************************************************/
// File: MyApp.cpp
// Summary: A simple program that measure how fast the user can write
//          the alphabet in the CLI.
//          Made as a lab assignment in the course 1DV534 OOP in C++ at LNU.
//          The assignment is for exploring the objec lifecykle, and is
//          therefore using "new" and "delete" as much as possible.
// Version: Version 1.0- 2018-04-11
// Author:  Ingrid Wiklund
// -------------------------------------------
// Log:  2018-04-10  Created the file. Ingrid
//       2018-04-11  Implemented basic functionality using classes
//                   "Clock", "MyTime" and the new "Compare".
/**********************************************************************/

#include <iostream>
#include <MyTime.h>
#include <Clock.h>
#include "Compare.h"

using std::cin;
using std::cout;

//const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
const char* ALPHABET = "abcdef"; // TODO: remove. Only for testing purpuses.

/**
* @brief Class MyApp for running this application. Call run() for running the program.
*/
class MyApp {
   enum {MAX_BUFFER_SIZE = 256};
   char stringBuffer[MAX_BUFFER_SIZE];
   void printProgramInfo();
   void printInstuctions();
   MyTime measureWritingTime();
   bool askUserIfContinue();
public:
   void run();
};


/**
* @brief Application runner. Will run until stopt by user.
*/
void MyApp::run()
{
   bool isEqual;
   bool contProgram = true;

   printProgramInfo();

   while (contProgram)
   {
      printInstuctions();

      MyTime time = measureWritingTime();

      // Compare with a correct alphabet.
      Compare *comparePtr = new Compare();
      isEqual = comparePtr->equal(ALPHABET, stringBuffer);
      delete comparePtr;

      // Show user the result.
      if (isEqual)
      {
         std::cout << "\nTime: " << time;
      }
      else
      {
         std::cout << "\nThat is not the alphabet.";
         std::cout << "\nYou wrote: " << stringBuffer;
         std::cout << "\nYou should have written: " << ALPHABET;
      }

      std::cout << "\n---------------------";
   
      contProgram = askUserIfContinue();
      system("cls");
   }
}

/**
* @brief Print program information to CLI.
*/
void MyApp::printProgramInfo()
{
   std::cout << "\nHow fast do you write?";
   std::cout << "\n----------------------";
   std::cout << "\n";
   std::cout << "\nThis simple program lets you test how fast you write by measuring how fast you can write the alphabet.";
}

/**
* @brief Print user instructions to CLI.
*/
void MyApp::printInstuctions()
{
   std::cout << "\n";
   std::cout << "\nInstruction:";
   std::cout << "\nPress enter.";
   std::cout << "\nWrite all lower case letters in alphabetic order ('" << ALPHABET << "'). ";
   std::cout << "\nPress enter again.";
   std::cout << "\nThe program will disply the time between enter and enter if the input was correct.";
   std::cout << "\n";
   std::cout << "\nStart by pressing enter...";
}

/**
* @brief Measure user writing time
* Measure the time between enter and enter from CLI and save user input to stringBuffer
* If there is more input than buffer size, clear and ignore CLI.
* @return the time as a MyTime object.
*/
MyTime MyApp::measureWritingTime()
{
   Clock *clockPtr = new Clock();

   // Wait for enter. (ignore any other char accedently hit before enter).
   std::cin.ignore(INT_MAX, '\n');
   // Start clock.
   MyTime timeStart = clockPtr->give_me_the_time();
   // Read line until enter.
   std::cin.getline(stringBuffer, MAX_BUFFER_SIZE);
   // Stop clock.
   MyTime timeStop = clockPtr->give_me_the_time();
   delete clockPtr; // Clock not needded anymore.

   // If there was too many chars for the buffer.
   if (std::cin.fail())
   {
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
   }
   return (timeStop - timeStart);
}

/**
* @brief Ask user if the want to run again.
* Ask for Y/N but interpret all unknown chars as a "no"
* and accept both 'Y' and 'y' as "yes".
* @return true if run agan.
* @return false if quit.
*/
bool MyApp::askUserIfContinue()
{
   bool cont = false;
   char answer;
   std::cout << "\nTry again (Y/N)?";
   std::cout << "\n";
   std::cin.get(answer);
   std::cin.ignore(INT_MAX, '\n');

   if (answer == 'Y' || answer == 'y')
   {
      cont = true;
   }

   return cont;
}

/**
* @brief Main function of application. Call MyApp.
*/
int main()
{
   MyApp alphabetTimerApp;
   alphabetTimerApp.run();
   return 0;
}