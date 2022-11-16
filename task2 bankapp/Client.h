
#ifndef TASK2_BANKAPP_CLIENT_H
#define TASK2_BANKAPP_CLIENT_H

#include <iostream>
#include "bankAccount.h"
#include "savinBank.h"
using namespace std;

class Client{
private:
    string name;
    string address;
    string phone;
    BankAccount *bankAcc;
    SavingBankA *savingAcc;
public:
    Client(string n, string a, string p, BankAccount* _bank);
    Client(string n, string a, string p, SavingBankA* bankAcc);
    string getName();
    string getAddress();
    string getPhoneNum();
};


#endif //TASK2_BANKAPP_CLIENT_H
