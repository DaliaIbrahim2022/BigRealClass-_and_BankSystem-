//
// Created by user on 11/14/2022.
//
#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt()
{
    cout << "enter your number \n";
    cin >> num;



    if (isValid(num)) {}


    else
    {
        cout << "not valid" << endl;
        exit(-1);
    }


}

bool BigDecimalInt :: operator !=(BigDecimalInt ob)
{
    int count = 0;

    if (num.size() == ob.num.size())
    {




        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] == ob.num[i])
            {
                count++;
            }
        }

        if ((count == num.size() - 1) && (num[0] == ob.num[0]))
        {
            return 0;
        }

        else if ((count == num.size() - 1) && num[0] == '+' && ob.num[0] != '-')
        {
            return 0;
        }
        else if ((count == num.size() - 1) && num[0] != '-' && ob.num[0] == '+')
        {
            return 0;

        }

        else
        {
            return 1;
        }
    }
    else
        return 1;
}
bool  BigDecimalInt ::operator > (BigDecimalInt ob)

{

    if (num.size() > ob.num.size() && (num[0] != '+' && num[0] != '-') && (ob.num[0] != '+' && ob.num[0] != '-'))
    {
        return 1;
    }

    if (num.size() < ob.num.size() && (num[0] != '+' && num[0] != '-') && (ob.num[0] != '+' && ob.num[0] != '-'))
    {
        return 0;
    }

    if (num.size() == ob.num.size() && (num[0] != '+' && num[0] != '-') && (ob.num[0] != '+' && ob.num[0] != '-'))
    {
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] > ob.num[i])
            {
                return 1;
                break;
            }
            else
                return 0;
            break;
        }
    }



    if (ob.num[0] == '-' && (num[0] >= 0 && num[0] <= 9))
    {

        return 1;

    }


    if (num[0] == '-' && (ob.num[0] >= 0 && ob.num[0] <= 9))
    {

        return 0;

    }





    if (num[0] == '+' && ob.num[0] == '-')
    {

        return 1;
    }

    else if (num[0] == '-' && ob.num[0] == '+')
    {
        return 0;
    }

    else if (num[0] == '+' && ob.num[0] == '+')

    {
        if (num.size() > ob.num.size())
        {
            return 1;
        }
    }

    else if (num[0] == '+' && ob.num[0] == '+')

    {
        if (num.size() < ob.num.size())
        {
            return 0;
        }
    }

    else if (num[0] == '+' && ob.num[0] == '+')

    {
        if (num.size() == ob.num.size())
        {
            for (int i = 1; i < num.size(); i++)
            {
                if (num[i] < ob.num[i])
                {
                    return 0;
                    break;
                }

                else if (num[i] > ob.num[i])
                {
                    return 1;
                    break;
                }
            }
        }
    }



    if (num[0] == '-' && ob.num[0] == '-')

    {
        if (num.size() == ob.num.size())
        {
            for (int i = 1; i < num.size(); i++)
            {
                if (num[i] < ob.num[i])
                {
                    return 1;
                    break;
                }

                else if (num[i] > ob.num[i])
                {
                    return 0;
                    break;
                }
            }
        }

        if (num.size() > ob.num.size())
        {
            return 0;
        }
        if (num.size() < ob.num.size())
        {
            return 1;
        }


    }

}


bool  BigDecimalInt ::operator < (BigDecimalInt ob)

{

    if (num.size() > ob.num.size() && (num[0] != '+' && num[0] != '-') && (ob.num[0] != '+' && ob.num[0] != '-'))
    {
        return false;
    }

    if (num.size() < ob.num.size() && (num[0] != '+' && num[0] != '-') && (ob.num[0] != '+' && ob.num[0] != '-'))
    {
        return true;
    }

    if (num.size() == ob.num.size() && (num[0] != '+' && num[0] != '-') && (ob.num[0] != '+' && ob.num[0] != '-'))
    {
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] > ob.num[i])
            {
                return false;
                break;
            }
            else
                return true;
            break;
        }
    }



    if (ob.num[0] == '-' && (num[0] >= 0 && num[0] <= 9))
    {

        return false;

    }


    if (num[0] == '-' && (ob.num[0] >= 0 && ob.num[0] <= 9))
    {

        return true;

    }





    if (num[0] == '+' && ob.num[0] == '-')
    {

        return false;
    }

    else if (num[0] == '-' && ob.num[0] == '+')
    {
        return true;
    }

    else if (num[0] == '+' && ob.num[0] == '+')

    {
        if (num.size() > ob.num.size())
        {
            return false;
        }
    }

    else if (num[0] == '+' && ob.num[0] == '+')

    {
        if (num.size() < ob.num.size())
        {
            return true;
        }
    }

    else if (num[0] == '+' && ob.num[0] == '+')

    {
        if (num.size() == ob.num.size())
        {
            for (int i = 1; i < num.size(); i++)
            {
                if (num[i] < ob.num[i])
                {
                    return true;
                    break;
                }

                else if (num[i] > ob.num[i])
                {
                    return false;
                    break;
                }
            }
        }
    }



    if (num[0] == '-' && ob.num[0] == '-')

    {
        if (num.size() == ob.num.size())
        {
            for (int i = 1; i < num.size(); i++)
            {
                if (num[i] < ob.num[i])
                {
                    return false;
                    break;
                }

                else if (num[i] > ob.num[i])
                {
                    return true;
                    break;
                }
            }
        }

        if (num.size() > ob.num.size())
        {
            return true;
        }
        if (num.size() < ob.num.size())
        {
            return false;
        }


    }

}


bool  BigDecimalInt :: operator ==(BigDecimalInt ob)
{
    int counter = 0;

    if (num.size() == ob.num.size())
    {
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] == ob.num[i])
            {
                counter++;
            }
            else
            {
                break;
            }
        }

        if ((counter == num.size()))
        {
            return 1;
        }

        else if ((counter == num.size() - 1) && num[0] == '+' && ob.num[0] != '-')
        {
            return 1;
        }
        else if ((counter == num.size() - 1) && num[0] != '-' && ob.num[0] == '+')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


void  BigDecimalInt::Equal(BigDecimalInt ob, BigDecimalInt ob2)
{
    if (ob == ob2)
    {
        cout << " they are Equal \n";
    }
    else
    {
        cout << " they are not Equal \n";
    }

}
void BigDecimalInt::greater(BigDecimalInt ob, BigDecimalInt ob2)
{
    if (ob != ob2)
    {
        if (ob > ob2)
            cout << ob.num << " is the greatest number \n";
        else
            cout << ob2.num << " is the greatest number \n";
    }

}

void BigDecimalInt::SizeNum(BigDecimalInt ob1, BigDecimalInt ob2)
{
    cout << "the size of first number = " << ob1.num.size() << endl;
    cout << "the size of second number = " << ob2.num.size() << endl;
}

bool BigDecimalInt::CHeckSign(BigDecimalInt ob)
{
    if (ob.num[0] == '+')
    {
        return 1;
    }
    else if (ob.num[0] == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void BigDecimalInt::smaller(BigDecimalInt ob, BigDecimalInt ob2)
{
    if (ob != ob2)
    {
        if (ob > ob2)
            cout << ob2.num << " is the smallest number \n";
        else
            cout << ob.num << " is the smallest number \n";
    }

}


//______________________________________________________________________________________________
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

}




/*
BigDecimalInt::BigDecimalInt()
{
    num="";
}

*/
BigDecimalInt::BigDecimalInt(string decstr)
{
    num = decstr;
}

BigDecimalInt::BigDecimalInt(int decint)
{
    if (decint < 0)
    {
        decint *= -1;

        while (decint != 0)
        {

            num += (decint % 10) + '0';
            decint -= decint % 10;
            decint /= 10;

        }
        num += '-';
    }



    else   if (decint == 0)
    {
        //cout<<"i'm here\n";
        num = "0";
    }


    else if (decint > 0) {
        while (decint != 0)
        {

            num += (decint % 10) + '0';
            decint -= decint % 10;
            decint /= 10;

        }
    }
    reverseStr(num);

}



ostream& operator<< (ostream& output, BigDecimalInt a)
{
    cout << a.num;
}




void removeleftzeros(string& a)
{
    if (a[0] == '0')
    {
        int i = 0;
        while (a[i] == '0')
            i++;

        if (i == (a.length()))
            a.erase(0, i - 1);
        else
            a.erase(0, i);
    }

    else if (a[0] == '-' && a[1] == '0')
    {
        int i = 0;
        while (a[i + 1] == '0')
            i++;
        if (i == a.length())
            a.erase(1, i - 1);
        else
            a.erase(1, i);
    }
}



bool checkvalid(BigDecimalInt& b)
{
    if (b.num[0] != '+' && b.num[0] != '-' && b.num[0] > '9' && b.num[0] < '0')
    {
        return 0;
    }
    for (int i = 1; i < b.num.length(); i++)
    {
        if (b.num[i] > '9' && b.num[i] < '0')
        {
            return 0;
        }
    }
    return 1;
}


bool checksign(BigDecimalInt& b)
{
    string c = "";
    if (b.num[0] == '-')
    {
        for (int i = 1; i < b.num.length(); i++)
        {
            c += b.num[i];
        }
        b.num = c;
        return 1;
    }

    else if (b.num[0] == '+')
    {

        for (int i = 1; i < b.num.length(); i++)
        {
            c += b.num[i];
        }
        b.num = c;
        return 0;

    }
    else
    {
        return 0;
    }


}


bool checkbigger(string a, string b)
{
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] > b[i])
            {

                return 1;
            }
            else if (b[i] > a[i])
            {

                return 0;
            }
        }

    }

}





bool checkequality(string a, string b)
{

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        else
            return 0;

    }

    return 1;
}



//________________________________________________________________
BigDecimalInt BigDecimalInt::    operator-(BigDecimalInt b)
{
    if (b.num[0] == '-' && (num[0] == '+' || (num[0] <= '9' && num[0] >= '0')))
    {
        checksign(b);
        return *this + b;
    }


    else if (num[0] == '-' && (b.num[0] == '+' || (b.num[0] <= '9' && b.num[0] >= '0')))
    {

        checksign(*this);
        return *this + b;

    }

    else if (b.num[0] == '-' && num[0] == '-')
    {
        checksign(b);
        checksign(*this);
        return b - *this;
    }


    if (num.length() > b.num.length())
    {

        int diff = num.length() - b.num.length();
        BigDecimalInt c;
        c.num = "";
        c.carry = 0;
        for (int i = (b.num.length() - 1); i >= 0; i--)
        {


            c.sum = 0;
            c.sum = num[i + diff] - b.num[i] + c.carry;
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }
            c.num += c.sum + '0';


        }

        for (int i = diff - 1; i >= 0; i--)
        {
            c.sum = 0;
            c.sum += num[i] + c.carry - '0';
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }

            c.num += c.sum + '0';
        }

        reverseStr(c.num);

        removeleftzeros(c.num);
        return c;




    }




    if (b.num.length() > num.length())
    {

        int diff = b.num.length() - num.length();
        BigDecimalInt c;
        c.num = "";
        c.carry = 0;
        for (int i = (num.length() - 1); i >= 0; i--)
        {


            c.sum = 0;
            c.sum = b.num[i + diff] - num[i] + c.carry;
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }
            c.num += c.sum + '0';


        }

        for (int i = diff - 1; i >= 0; i--)
        {
            c.sum = 0;
            c.sum += b.num[i] + c.carry - '0';
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }
            c.num += c.sum + '0';
        }

        c.num += '-';

        reverseStr(c.num);
        removeleftzeros(c.num);

        return c;




    }

    if (num.length() == b.num.length())
    {
        if (checkequality(num, b.num))
        {
            BigDecimalInt c;
            c.num = "0";
            return c;
        }

        if (checkbigger(num, b.num))
        {



            BigDecimalInt c;
            c.num = "";
            c.carry = 0;
            for (int i = (num.length() - 1); i >= 0; i--)
            {


                c.sum = 0;
                c.sum = num[i] - b.num[i] + c.carry;
                c.carry = 0;
                if (c.sum < 0)
                {
                    c.sum += 10;
                    c.carry--;
                }
                c.num += c.sum + '0';


            }


            reverseStr(c.num);

            removeleftzeros(c.num);
            return c;
        }

        else if (checkbigger(b.num, num))
        {

            BigDecimalInt c;
            c.num = "";
            c.carry = 0;
            for (int i = (b.num.length() - 1); i >= 0; i--)
            {
                c.sum = 0;
                c.sum = b.num[i] - num[i] + c.carry;
                c.carry = 0;
                if (c.sum < 0)
                {
                    c.sum += 10;
                    c.carry--;
                }
                c.num += c.sum + '0';
            }
            c.num += '-';
            reverseStr(c.num);
            removeleftzeros(c.num);

            return c;
        }
    }
}
//____________________________________________
//opertor plus
BigDecimalInt BigDecimalInt :: operator+(BigDecimalInt d2)
{
    //string num;
    string res;
    int carry = 0;
    char sign1, sign2;

    if (!isdigit(num[0]))
    {
        sign1 = num[0];
        // s1.erase(remove(s1.begin() , s1.end() ,s1[0]),s1.end());
        num.erase(0, 1);
    }
    if (!isdigit(d2.num[0]))
    {
        sign2 = d2.num[0];
        // d2.s1.erase(remove(d2.s1.begin() , d2.s1.end() ,d2.s1[0]),d2.s1.end());
        d2.num.erase(0, 1);
    }
    if (num.size() > d2.num.size())
    {
        int x = num.size() - d2.num.size();
        d2.num = string(x, '0').append(d2.num);
    }
    else if (num.size() < d2.num.size())
    {
        int x = d2.num.size() - num.size();
        num = string(x, '0').append(num);
    }
    if (sign1 == '-' && sign2 == '-')
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            int sum = 0;

            sum = (num[i] - '0') + (d2.num[i] - '0') + carry;

            if (sum < 10)
            {
                res += to_string(sum);
                carry = 0;
            }
            else
            {
                res.push_back(sum % 10 + '0');
                carry = 1;
                if (i == 0)
                    res.push_back(1 + '0');
            }
        }
        res += '-';
    }
        //______________________
       // if the two numbers are a different signs
//    else if (sign1 == '-' && (sign2 == '+' || sign2 == ' '))
//    {
//        if (num > d2.num)
//        {
//            res = (num - d2.num);
//            res += '-';
//        }
//        else
//            res = num + d2.num;
//    }
    else
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            int sum = 0;

            sum = (num[i] - '0') + (d2.num[i] - '0') + carry;

            if (sum < 10)
            {
                res += to_string(sum);
                carry = 0;
            }
            else
            {
                res.push_back(sum % 10 + '0');
                carry = 1;
                if (i == 0)
                    res.push_back(1 + '0');
            }
        }
    }
    //_________________________________
    reverse(res.begin(), res.end());
    return BigDecimalInt(res);
}

//   void display()
//   {
//     cout << num << endl;
//   }





//____________________________________________
int BigDecimalInt::size()
{
    return num.length();
}


bool isValid(string s)
{
    regex pattern("[-+]?([0-9]*\\.[0-9]+|[0-9]+)");
    if (regex_match(s, pattern))
    {
        return true;
    }

    else
    {
        return false;
    }

}