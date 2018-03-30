#ifndef FILE_H
#define FILE_H

#include "Values.h"
#include <string>

using std::string;

/**
* @brief    Class for reading values from a file
*/
class File
{
   const string filePath;
public:
   File();
   File(string);
   ~File();
   bool readValuesFromFile(Values* buffer, int num_of_values);
};

#endif /* FILE_H */