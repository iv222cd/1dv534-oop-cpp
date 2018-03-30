#include "Values.h"
#include <fstream>

using std::ifstream;

/**
* @brief    Basic Constructor
*/
Values::Values() : inFileName_(""), numberOfValues_(0), min_(0), max_(0), average_(0), bufferValid_(false)
{
}

/**
* @brief    Parameterized Constructor
*/
Values::Values(string inFileName, int numOfValues) : inFileName_(inFileName), numberOfValues_(numOfValues), min_(0), max_(0), average_(0), bufferValid_(false)
{
}

/**
* @brief    Copy constructor
*/
Values::Values(const Values& old_values)
{
   numberOfValues_ = old_values.numberOfValues_;
   max_ = old_values.max_;
   min_ = old_values.min_;
   average_ = old_values.average_;
   bufferValid_ = old_values.bufferValid_;
   inFileName_ = old_values.inFileName_;

   for (int i = 0; i < numberOfValues_; i++)
   {
      buffer_[i] = old_values.buffer_[i];
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

   if (numberOfValues_ < MAX)
   {
      ifstream file(inFileName_);

      if (file.is_open())
      {
         bufferValid_ = true;

         for (int i = 0; i < numberOfValues_; i++)
         {
            file >> buffer_[i];

            if (!file)
            {
               bufferValid_ = false;
               break;
            }
         }
         file.close();
      }
   }
   return bufferValid_;
}

/**
* @brief   Calculate and store statistics (min, max, average) for the values in Values buffer.
*
* @note     Do not call before readValuesFromFile()
*/
void Values::doCalulations()
{
   if (bufferValid_ && numberOfValues_ > 0)
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
}