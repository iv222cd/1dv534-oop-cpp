// TODO write file header.

#include <iostream>
#include <MyTime.h>
#include <Clock.h>
#include "Compare.h"

using std::cin;
using std::cout;

const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";

class MyApp {
public:
   void run();
};

void MyApp::run()
{
   bool isEqual;

   // Print instuctions to user.
   // Wait for enter.
   // Start clock.
   // Read line until enter.
   // Stop clock.
   // Compare.
   // Show user the result.
   
   Compare *comparePtr = new Compare();
   isEqual = comparePtr->equal(ALPHABET, ALPHABET);
   delete comparePtr;
}

int main()
{
   MyApp alphabetTimerApp;
   alphabetTimerApp.run();
   return 0;
}