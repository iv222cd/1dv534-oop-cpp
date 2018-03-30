#ifndef VALUES_H
#define VALUES_H

/**
* @brief    Class for storing values and calculating statistics
*/
class Values
{
   enum {MAX = 100};
   double buffer[MAX];
   int numberOfValues;
   double min, max, average;
public:
   Values();
   Values(const Values& old_values);
   ~Values();
   void addValue(double newValue);
   void doCalulations();
   double getMin() { return min; }
   double getMax() { return max; }
   double getAverage() { return average; }
   double getValue(int index) { return buffer[index]; }
   double getNumberOfValues() { return numberOfValues; }
};

#endif /* VALUES_H */