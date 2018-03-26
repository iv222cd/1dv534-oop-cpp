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

/**
* @brief    Class for running the application miserable.
*/
class miserableApplication
{
   bool terminate;      // Set to true if the application should terminate.
   int status;          // Application status. Ok is 0.
   Menu menu;           // Menu object
public:
   miserableApplication();
   ~miserableApplication();
   int run();
};

/**
* @brief    Constructor
*/
miserableApplication::miserableApplication()
{
   terminate = false;
   status = 0;
}

/**
* @brief    Destructor
*/
miserableApplication::~miserableApplication()
{

}

/**
* @brief    Run the application until the user terminates ut.
* 
* @return   Application termination status. Status ok if 0, error otherwise.
*/
int miserableApplication::run()
{
   return 0;
}

int main()
{
   miserableApplication app;

   return app.run();
}