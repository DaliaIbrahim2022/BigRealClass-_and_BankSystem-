#include "BigDecClass.h"
#include <regex>
#include<iostream>
#include <string>

class BigReal {
private:
    string number;
    BigDecimalInt real;
    BigDecimalInt fraction;
    string real_num;
    int dotPosition;
    char signn;
public:
   // BigReal (double realNumber);
    BigReal( string  realNumber);
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
   bool operator<(const BigReal & other);
   bool operator>(const BigReal & other);
    string getNumber() { return number; }
//    BigReal(BigDecimalInt bigDecimalInt);
//    void ret();
    friend ostream &operator << (ostream &out, BigReal num);

};










