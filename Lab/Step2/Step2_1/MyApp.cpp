// TODO write file header.

#include <iostream>
#include <MyTime.h>
#include <Clock.h>
#include "Compare.h"

using std::cin;
using std::cout;

//const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
const char* ALPHABET = "abcdef"; // TODO: remove. Only for testing purpuses.

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


void MyApp::printProgramInfo()
{
   std::cout << "\nHow fast do you write?";
   std::cout << "\n----------------------";
   std::cout << "\n";
   std::cout << "\nThis simple program lets you test how fast you write by measuring how fast you can write the alphabet.";
}

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

bool MyApp::askUserIfContinue()
{
   bool cont = false;
   std::cout << "\nTry again (Y/N)?";
   std::cout << "\n";
   std::cin.getline(stringBuffer, MAX_BUFFER_SIZE);
   if (stringBuffer[0] == 'Y' || stringBuffer[0] == 'y')
   {
      cont = true;
   }
   return cont;
}

int main()
{
   MyApp alphabetTimerApp;
   alphabetTimerApp.run();
   return 0;
}