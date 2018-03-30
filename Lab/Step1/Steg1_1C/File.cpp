#include "File.h"
#include <fstream>

#include <iostream> //TODO remove

using std::ifstream;

File::File()
{
   std::cout << "\nConstructing File";
}

File::File(string filePathIn) : filePath(filePathIn)
{
   std::cout << "\nConstructing File : " << filePathIn;
}


File::~File()
{
   std::cout << "\nDestructing File";
}

bool File::readValuesFromFile(Values* buffer, int num_of_values)
{
   bool status = true;
   ifstream file(filePath);
   if (file.is_open())
   {
      double tmp;
      for (int i = 0; i < num_of_values; i++)
      {
         file >> tmp;
         if (!file)
         {
            status = false;
            break;
         }
         buffer->addValue(tmp);
      }
      file.close();
   }
   else
   {
      status = false;
   }
   return status;
}