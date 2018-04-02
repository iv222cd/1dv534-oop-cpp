#include "Values.h"
#include <fstream>

using std::ifstream;

/**
* @brief    Basic Constructor
*/
Values::Values() : inFileName(""), numberOfValues(0), min(0), max(0), average(0), bufferValid(false)
{
}

/**
* @brief    Parameterized Constructor
*/
Values::Values(string inFileName, int numOfValues) : inFileName(inFileName), numberOfValues(numOfValues), min(0), max(0), average(0), bufferValid(false)
{
}

/**
* @brief    Copy constructor
*/
Values::Values(const Values& old_values)
{
   numberOfValues = old_values.numberOfValues;
   max = old_values.max;
   min = old_values.min;
   average = old_values.average;
   bufferValid = old_values.bufferValid;
   inFileName = old_values.inFileName;

   for (int i = 0; i < numberOfValues; i++)
   {
      buffer[i] = old_values.buffer[i];
   }
}

/**
* @brief    Destructor
*/
Values::~Values()
{
}

/**
* @brief    Read values from file and stor in internal buffer. 
*
* @return   true     if successfull and values in buffer is valid.
* @return   false    if not successfull
*/
bool Values::readValuesFromFile()
{
   bool status = false;

   if (numberOfValues < MAX)
   {
      ifstream file(inFileName);

      if (file.is_open())
      {
         bufferValid = true;

         for (int i = 0; i < numberOfValues; i++)
         {
            file >> buffer[i];

            if (!file)
            {
               bufferValid = false;
               break;
            }
         }
         file.close();
      }
   }
   return bufferValid;
}

/**
* @brief   Calculate and store statistics (min, max, average) for the values in Values buffer.
*
* @note     Do not call before readValuesFromFile()
*/
void Values::doCalulations()
{
   if (bufferValid && numberOfValues > 0)
   {
      average = 0;
      if (numberOfValues > 0)
      {
         min = buffer[0];
         max = buffer[0];
         for (int i = 0; i < numberOfValues; i++)
         {
            average += buffer[i];
            if (buffer[i] > max)
               max = buffer[i];
            if (buffer[i] < min)
               min = buffer[i];
         }
         average /= numberOfValues;
      }
      else
      {
         min = max = 0;
      }
   }
}