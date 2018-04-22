#ifndef TEST_FAIL_EXCEPTION_H
#define TEST_FAIL_EXCEPTION_H

#include <string>
#include "Fraction.h"

using std::string;
/**
* @brief    Super simple class for storing a Test Fail Exception
*/
class TestFailException
{
   string _message;
public:
   TestFailException(const string& msg) : _message(msg) {}
   string getMessage() const { return _message; }
};

#endif /* TEST_FAIL_EXCEPTION_H */
