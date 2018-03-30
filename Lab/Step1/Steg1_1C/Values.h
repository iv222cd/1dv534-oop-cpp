#ifndef VALUES_H
#define VALUES_H

#include <string>
#include <iostream>

using std::string;

/**
* @brief    Class for reading and storing values and calculating statistics
*/
class Values
{
   enum {MAX = 100}; // Maximum values that can be stored in the object.
   double buffer_[MAX]; // Buffer for storing values
   int numberOfValues_; // Number of values to store in the buffer.
   double min_, max_, average_; // Calculated statistics. Not valid until a call to doCalulations
   string inFileName_; // File name for file with values to read.
public:
   Values();
   Values(string inFileName, int numOfValues) : inFileName_(inFileName), numberOfValues_(numOfValues) {}
   Values(const Values& old_values);
   ~Values();
   bool readValuesFromFile();
   void doCalulations();
   double getMin() { return min_; }
   double getMax() { return max_; }
   double getAverage() { return average_; }
   double getValue(int index) { return buffer_[index]; }
   double getNumberOfValues() { return numberOfValues_; }
   string getInFileName() { return inFileName_; }
};

#endif /* VALUES_H */