#include "Values.h"
#include <fstream>

#include <iostream> //TODO remove
//TODO write function headers

using std::ifstream;

Values::Values() : numberOfValues_(0)
{
   std::cout << "\n--Constructing Values";
}

Values::Values(const Values& old_values)
{
   std::cout << "\n--Copying Values";
   numberOfValues_ = old_values.numberOfValues_;
   max_ = old_values.max_;
   min_ = old_values.min_;
   average_ = old_values.average_;

   for (int i = 0; i < numberOfValues_; i++)
   {
      buffer_[i] = old_values.buffer_[i];
   }
}

Values::~Values()
{
   std::cout << "\n--Destructing Values";
}

bool Values::readValuesFromFile()
{
   bool status = false;

   if (numberOfValues_ < MAX)
   {
      ifstream file(inFileName_);

      if (file.is_open())
      {
         status = true;

         for (int i = 0; i < numberOfValues_; i++)
         {
            file >> buffer_[i];

            if (!file)
            {
               status = false;
               break;
            }
         }
         file.close();
      }
   }
   return status;
}

void Values::doCalulations()
{
   average_ = 0;
   if (numberOfValues_ > 0)
   {
      min_ = buffer_[0];
      max_ = buffer_[0];
      for (int i = 0; i < numberOfValues_; i++)
      {
         average_ += buffer_[i];
         if (buffer_[i] > max_)
            max_ = buffer_[i];
         if (buffer_[i] < min_)
            min_ = buffer_[i];
      }
      average_ /= numberOfValues_;
   }
   else
   {
      min_ = max_ = 0;
   }
}
