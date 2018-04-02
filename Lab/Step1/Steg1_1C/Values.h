#ifndef VALUES_H
#define VALUES_H

#include <string>

using std::string;

/**
* @brief    Class for reading, storing and calculating statistics for a number of values
* 
* The values is collected from file with the function readValuesFromFile().
* The values in the file needs to be numeric (decimal) and space separated.
*/
class Values
{
   enum {MAX = 100};             // Maximum values that can be stored in the object.
   double buffer[MAX];          // Buffer for storing values
   bool bufferValid;            // Flag indicating the validity of buffer
   int numberOfValues;          // Number of values to store in the buffer.
   double min, max, average;  // Calculated statistics. Not valid until a call to doCalulations
   string inFileName;           // File name for file with values to read.
public:
   Values();
   Values(string inFileName, int numOfValues);
   Values(const Values& old_values);
   ~Values();
   bool readValuesFromFile();
   void doCalulations();
   double getMin() { return min; }
   double getMax() { return max; }
   double getAverage() { return average; }
   double getNumberOfValues() { return numberOfValues; }
   double getValue(int index) { return buffer[index]; }
   string getInFileName() { return inFileName; }
};

#endif /* VALUES_H */