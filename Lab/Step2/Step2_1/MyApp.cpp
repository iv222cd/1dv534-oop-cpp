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
public:
   void run();
};

void MyApp::run()
{
   bool isEqual;
   char userAlphabet[256];

   // Program info
   std::cout << "\nHow fast do you write?";
   std::cout << "\n----------------------";
   std::cout << "\n";
   std::cout << "\nThis simple program lets you test how fast you write by measuring how fast you can wirte the alphabet.";

   // Print instuctions to user.
   std::cout << "\n";
   std::cout << "\nInstruction:";
   std::cout << "\nPress enter, then write all lower case letter in the alphabet in order,";
   std::cout << "\ni.e. '" << ALPHABET << "'. Then press enter again.";
   std::cout << "\nThe program will measure the time beteen enter and enter.";
   std::cout << "\n";
   std::cout << "\nStart by pressing enter...";

   Clock *clockPtr = new Clock();

   // Wait for enter.
   std::cin.get();
   // Start clock.
   MyTime timeStart = clockPtr->give_me_the_time();
   // Read line until enter.
   std::cin.getline(userAlphabet, 256);
   // Stop clock.
   MyTime timeStop = clockPtr->give_me_the_time();
   delete clockPtr;

   
   // Compare.
   Compare *comparePtr = new Compare();
   isEqual = comparePtr->equal(ALPHABET, userAlphabet);
   delete comparePtr;

   // Show user the result.
   if (isEqual)
   {
      std::cout << "\ncorrect written";
      std::cout << "\ntime is ...";
      std::cout << (timeStop - timeStart);
      std::cout << "\n-----------";
   }
   else
   {
      std::cout << "\nNot correctly written!";
      std::cout << "\nYou should have written: " << ALPHABET;
   }

   // todo: start again (loop).
   std::cin.get();

}

int main()
{
   MyApp alphabetTimerApp;
   alphabetTimerApp.run();
   return 0;
}