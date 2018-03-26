#ifndef VALUES_H
#define VALUES_H

/**
* @brief    Class for storing values and calculating statistics
*/
class Values
{
   double buffer[100];
   int numberOfValues;
public:
   Values();
   ~Values();
   void addValue(double newValue);
   void doCalulations();
   double getMin();
   double getMax();
   double getAverage();
};

#endif /* VALUES_H */