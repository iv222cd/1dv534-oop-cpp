#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include <fstream>

using std::ofstream;

/**
* Class for maintaing a cash register.
* Items added to the cash register is printed to file.
*/
class CashRegister {
public:
   CashRegister(const char* fileName, int nrOfCategories); // The file contains
   ~CashRegister(); // registered items and balances
   bool registerItem(int category, const char* articleName, double amount);
   double batchTotal() {
      double total = _batchTotal;
      _batchTotal = 0; // batchTotal() is expected to reset _batchTotal;
      return total;
   }
private:
   void setTimeNowString(char* buffer, size_t sizeOfBuffer, const char* format);
   ofstream _file; // Here will registered items be saved
   int _nrOfCategories; // Products are organized in categories
   double* _categorySums; // The vector will contain respective sum of each
                          // category sold during the day
   double _batchTotal; // Sold since the last summation
};

#endif /* CASH_REGISTER_H */