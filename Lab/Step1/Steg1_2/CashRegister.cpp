#include <ctime>
#include <iomanip>

#include "CashRegister.h"

#include <iostream>

const char *LONG_TIME_DATE_FORMAT = "%F  %A  at  %R"; // Example: 2018-04-02  Monday  at  23:15
const char *SHORT_TIME_FORMAT = "%R"; // 23:15

/**
* @brief Overloaded Constructor for CashRegister.
*
* Sets Number of categories, initlizes needed variables, opens output file "fileName" and prints open information.
* 
* @param    fileName          Path to register file. Object will open and append text to this file.
* @param    nrOfCategories    Number of categories in the cash register.
*/
CashRegister::CashRegister(const char* fileName, int nrOfCategories) : _nrOfCategories(nrOfCategories), _batchTotal(0)
{
   // Allocating memory for the category sum and initilizing to 0
   _categorySums = new double[nrOfCategories];
   memset(_categorySums, 0, sizeof(*_categorySums)*nrOfCategories);

   // Get string with todays date and time.
   char timeString[40];
   setTimeNowString(timeString, sizeof(timeString), LONG_TIME_DATE_FORMAT);

   _file.open(fileName, std::ofstream::app);

   if (_file.is_open())
   {
      // Set some common formating of file
      _file.precision(2);
      _file.setf(std::ios::fixed);
      _file.setf(std::ios::right);

      _file << ">>>>> Register opened: " << timeString << "\n";
   }
}

/**
* @brief Destructor for CashRegister.
*
* Prints close information and closes putput file. Freeing allocated memory.
*/
CashRegister::~CashRegister()
{
   double total = 0;

   char timeString[40];
   setTimeNowString(timeString, sizeof(timeString), LONG_TIME_DATE_FORMAT);

   if (_file.is_open())
   {
      _file << ">>>>> Register closed: " << timeString << "\n";
      _file << "Category totals for last opening period:\n";
      _file << "----------------------------------------\n";

      for (int i = 0; i < _nrOfCategories; i++)
      {
         _file << "Category " << std::setw(3) << i + 1 << " :" << std::setw(10) << _categorySums[i] << " Kr.\n";
         total += _categorySums[i];
      }
      _file << "Total sales within all categories: " << total << " Kr.\n";
      _file << "==========================================================================\n";
      _file.close();
   }
   delete[] _categorySums;
}

/**
* @brief Add item to cash register.
* 
* Add amout to total sums and add information to output file.
*
* @param    category       Number of category. Valid values as 1 to _nrOfCategories.
*                          Will not preform any action if parameter not valid.
* @param    articleName    String with article name.
* @param    amout          Cost for the article.
*
* @return   true   If category is valid.
* @return   false  If category is out of bound.
*/
bool CashRegister::registerItem(int category, const char* articleName, double amount)
{
   bool result = false;

   if ((category - 1 < _nrOfCategories) && (category - 1 >= 0))
   {
      char timeString[40];

      result = true;
      _categorySums[category - 1] += amount;
      _batchTotal += amount;

      setTimeNowString(timeString, sizeof(timeString), SHORT_TIME_FORMAT);

      if (_file.is_open())
      {
         _file << timeString << " : Cat." << std::setw(3) << category << " :" << std::setw(13) << amount << " Kr. [ " << articleName << " ]\n";
      }
   }
   return result;
}

/** Private Methods **********************************************************/

/**
* @brief    Copy current date and time on specified format to buffer.
*
* If the buffer is to small, no string will be copied.
*
* @param    buffer         Number of category. Valid values as 1 to _nrOfCategories.
*                          Will not preform any action if parameter not valid.
* @param    sizeOfBuffer   Size of buffer.
* @param    format         Set format the output string. See foramt for std::strftime for specification.
*/
void CashRegister::setTimeNowString(char* buffer, size_t sizeOfBuffer, const char* format)
{
   // Kommentar angående implementation av datumstämpel till registerfilen.
   // 
   // Följde dokumentationen av ctime på www.cplusplus.com/reference/ctime/.
   // Hämtar "nu"-tiden (i sek sen epoch) med std::time.
   // Omvandlar till en tid-struct med info för lokal tid med localtime_s.
   // Skriver ut informationen i structen till en sträng på specifierat format med std::strftime.
   // Använde först localtime men bytte sen till localtime_s eftersom den föregående är "deprecated".
   // Stötte inte på några speciella andra svårigheter med implementeringen då dokumentationen är rättfram och enkel att följa.

   std::time_t time = std::time(nullptr);
   struct std::tm timeInfo;
   localtime_s(&timeInfo, &time);
   std::strftime(buffer, sizeOfBuffer, format, &timeInfo);
}