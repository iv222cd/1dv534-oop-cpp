#include "Values.h"

#include <iostream> //TODO remove
//TODO write function headers

Values::Values() : numberOfValues(0)
{
   std::cout << "\nConstructing Values";
}

Values::Values(const Values& old_values)
{
   std::cout << "\nCopying Values";
   numberOfValues = old_values.numberOfValues;
   max = old_values.max;
   min = old_values.min;
   average = old_values.average;

   for (int i = 0; i < numberOfValues; i++)
   {
      buffer[i] = old_values.buffer[i];
   }
}

Values::~Values()
{
   std::cout << "\nDestructing Values";
}


void Values::addValue(double newValue)
{
   if (numberOfValues < MAX)
   {
      buffer[numberOfValues] = newValue;
      numberOfValues++;
   }
}

void Values::doCalulations()
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

//double Values::getMin()
//{
//   return 0.0;
//}
//
//double Values::getMax()
//{
//   return 0.0;
//}
//
//double Values::getAverage()
//{
//   return 0.0;
//}