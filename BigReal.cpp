#include "BigReal.h"
#include<iostream>
#include<string>
BigReal::BigReal(string realNumber) {

    regex rej_pattern("[+-]?[0-9]+(\\.[0-9]+)?");

    if(regex_match(realNumber,rej_pattern)) {
        if(realNumber[0] =='-') {
            signn='-';
            realNumber.erase(realNumber.begin());
        }
        else {
            signn='+';
            if(realNumber[0]=='+')
                realNumber.erase(realNumber.begin());
        }
        string temp="";
        bool t=0;
        for(long long i=0; i<realNumber.size() ; i++){
            if(realNumber[i]=='0'&& t==0 ){
                continue;
            }
            else {
                t=1;
                temp+=realNumber[i];
            }

        }
        if(temp[0]=='.'){
            temp='0'+temp;
        }
        real_num=temp;
        string r="",f="";
        bool test=0;
        for(long long i=0 ; i<real_num.size(); i++){
            if(real_num[i]=='.') {
                test = 1;
                continue;
            }
            if(test==0) r+=real_num[i];
            else f+=real_num[i];
        }
        fraction= f;
        real= BigDecimalInt(r);

    }

    else
        throw("error name");
}
bool BigReal::operator<(const BigReal & other)
{
    if((real < other.real  || (real == other.real && fraction < other.fraction))  && (signn == '+'  and  other.signn == '+'))
        return true;
    else if (signn == '-' && other.signn =='-' && (real > other.real  || (real == other.real && fraction > other.fraction))  )
        return true;
    else if (signn == '-' and other.signn == '+')
        return true;
    else
        return false;
}
//_____________________________________________
bool BigReal::operator>(const BigReal & other)
{

    if((real > other.real  || (real == other.real && fraction > other.fraction))  && (signn == '+'  and  other.signn == '+'))
        return true;
    else if (signn == '-' && other.signn =='-' && (real < other.real  || (real == other.real && fraction < other.fraction))  )
        return true;
    else if (signn =='+' and other.signn == '-')
        return true;
    else
        return false;
}
//_____________________________________________
//______________________________________________
BigReal BigReal::operator+(BigReal & number2) {
    BigReal result("0.0");
    BigReal number1 = *this;
    int maximum = max(fraction.size(), number2.fraction.size());
    int minimum = min(fraction.size(), number2.fraction.size());
    result.real = real + number2.real;
    while (minimum < maximum) {
        if (fraction.size() < number2.fraction.size()) {
            fraction.push_back('0');
        } else {
            number2.fraction.push_back('0');
        }
        minimum++;
    }
    if (signn == number2.signn) {
        result.fraction = fraction + number2.fraction;
        if (result.fraction.size() > maximum) {
            result.real = result.real + BigDecimalInt("1");
            string ss = result.fraction.getNumber();
            for (int i = 0; i < result.fraction.size() - maximum; i++) {
                ss.erase(ss.begin());
            }
            result.fraction.setNumber(ss);
            result.signn = number2.signn;
        } else if (result.fraction.size() < minimum) {
            string s = " ";
            for (int i = 0; i < maximum - result.fraction.size(); i++) {
                s += "0";
            }
            cout << s << endl;
            s += result.fraction.getNumber();
            result.fraction = BigDecimalInt(s);
            result.signn = number2.signn;
        } else {
            result.signn = number2.signn;
        }
        return result;
    }else
    {
        if (number1.real > number2.real ){
            result.signn = number1.signn;
            result.real = number1.real - number2.real;
            if(number1.fraction > number2.fraction) {
                result.fraction = fraction - number2.fraction;
            }else if(number1.fraction < number2.fraction){
                string str=fraction.getNumber();
                str[0]+=10;
                fraction.setNumber(str);
                result.real = result.real - BigDecimalInt("1");
                result.fraction = fraction - number2.fraction;
            }else{
                result.fraction = fraction - number2.fraction;}
        }
        else if (number1.real < number2.real){
            result.signn = number2.signn;
            result.real = number2.real - number1.real;
            if(number1.fraction > number2.fraction) {
                string str = number2.fraction.getNumber();
                str[0] += 10;
                number2.fraction.setNumber(str);
                result.real = result.real - BigDecimalInt("1");
                result.fraction = number2.fraction - number1.fraction;
            }else if(number1.fraction < number2.fraction){
                result.fraction = number2.fraction - number1.fraction;
            }else{
                result.fraction = number2.fraction - number1.fraction;
            }
        }else if (number1.real == number2.real && number1.fraction == number2.fraction){
            result.real = number2.real - number1.real;
            result.fraction = number2.fraction - number1.fraction;
        }else if (number1.real == number2.real && number1.fraction > number2.fraction){
            result.signn = number1.signn;
            result.real = number1.real - number2.real;
            result.fraction = number1.fraction - number2.fraction;
        }else if(number1.real == number2.real && number1.fraction < number2.fraction){
            result.signn = number2.signn;
            result.real = number2.real - number1.real;
            result.fraction = number2.fraction - number1.fraction;
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________
//_______________________________________________________
BigReal BigReal::operator-(BigReal &other) {
    BigReal result("0.0");
    BigReal left = *this;
    BigReal right = other.real_num;
    int maximum = max(fraction.size(), other.fraction.size());
    int minimum = min(fraction.size(), other.fraction.size());
    result.real = real - other.real;
    while (minimum < maximum) {
        if (fraction.size() < other.fraction.size()) {
            fraction.push_back('0');
        } else {
            other.fraction.push_back('0');
        }
        minimum++;
    }
    //_________________________________________________________________________________________________________________________________________________________
    if (left.signn =='+'&& other.signn=='+')
    {
        if (left.real > other.real)
        {
            result.signn = left.signn;
            result.real = left.real - other.real;
            if (left.fraction > other.fraction) {
                result.fraction = left.fraction - other.fraction;
            }else if (left.fraction < other.fraction){
                string str = left.fraction.getNumber();
                str[0] += 10;
                left.fraction.setNumber(str);
                result.real = result.real- BigDecimalInt("1");
                result.fraction = left.fraction - other.fraction;
            }else{
                result.fraction = left.fraction - other.fraction;
            }
        }
        else if (left.real < other.real)
        {result.signn = '-';
            result.real = other.real - left.real;
            if (left.fraction > other.fraction) {
                string str = other.fraction.getNumber();
                str[0] += 10;
                other.fraction.setNumber(str);
                result.real = result.real - BigDecimalInt("1");
                result.fraction = other.fraction - left.fraction;
            } else if (left.fraction < other.fraction) {
                result.fraction = other.fraction - left.fraction;
            }else{
                result.fraction = other.fraction - left.fraction;
            }
        }
        else if (left.real == other.real) {
            if (left.fraction > other.fraction) {
                result.signn = '+';
                result.real = left.real - other.real;
                result.fraction = left.fraction - other.fraction;
            } else if (left.fraction < other.fraction) {
                result.signn = '-';
                result.real = other.real - left.real;
                result.fraction = other.fraction - left.fraction;
            }else{
                result.fraction = other.fraction - left.fraction;
            }
        }
    }
    else if(left.signn =='-'&& other.signn=='-')
    {
        if (left.real > other.real) {
            result.signn = left.signn;
            result.real = left.real - other.real;
            if (left.fraction > other.fraction) {
                result.fraction = left.fraction - other.fraction;
            }else if (left.fraction < other.fraction){
                string str = left.fraction.getNumber();
                str[0] += 10;
                left.fraction.setNumber(str);
                result.real = result.real- BigDecimalInt("1");
                result.fraction = left.fraction - other.fraction;
            }else{
                result.fraction = left.fraction - other.fraction;
            }
        }else if (left.real < other.real)
        {result.signn = '+';
            result.real = other.real - left.real;
            if (left.fraction > other.fraction) {
                string str = other.fraction.getNumber();
                str[0] += 10;
                other.fraction.setNumber(str);
                result.real = result.real - BigDecimalInt("1");
                result.fraction = other.fraction - left.fraction;
            } else if (left.fraction < other.fraction) {
                result.fraction = other.fraction - left.fraction;
            }else{
                result.fraction = other.fraction - left.fraction;
            }
        }
        else if (left.real == other.real) {
            if (left.fraction > other.fraction) {
                result.signn = '-';
                result.real = left.real - other.real;
                result.fraction = left.fraction - other.fraction;
            } else if (left.fraction < other.fraction) {
                result.signn = '+';
                result.real = other.real - left.real;
                result.fraction = other.fraction - left.fraction;
            }else{
                result.fraction = other.fraction - left.fraction;
            }
        }
    }
    else
    {
        if(left.signn=='+'&& other.signn=='-')
        {result.signn = '+';}
        else{result.signn = '-';}
            result.real = left.real + other.real;
            result.fraction = left.fraction + other.fraction;
            if (result.fraction.size() > maximum) {
                result.real = result.real + BigDecimalInt("1");
                string ss = result.fraction.getNumber();
                for (int i = 0; i < result.fraction.size() - maximum; i++) {
                    ss.erase(ss.begin());}
                result.fraction.setNumber(ss);
            } else if (result.fraction.size() < minimum) {
                string s = " ";
                for (int i = 0; i < maximum - result.fraction.size(); i++) {
                    s += "0";}
                cout << s << endl;
                s += result.fraction.getNumber();
                result.fraction = BigDecimalInt(s);}
    }
    return result;
}
//________________________________________________________
ostream &operator << (ostream &out, BigReal num)
{
    if(num.signn=='-')
        out<<'-';
    out<<num.real;
    if(num.fraction.getNumber()!="0")
        out<<'.'<<num.fraction;
    return out;
}
