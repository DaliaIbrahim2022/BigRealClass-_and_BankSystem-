
#ifndef TASK2_BANKAPP_BANKACCOUNT_H
#define TASK2_BANKAPP_BANKACCOUNT_H
#include <iostream>
#include<string>
using namespace std;

class BankAccount
{
protected:
    string ID;
    double balance;
    static int cnt;
public:
    BankAccount();
    BankAccount(string accId ,double bal);
    void SetAccId(string accId);
    void SetBalance(double bal);
    double GetBalance();
    string GetAccId();
   virtual int withdraw(double x);
    virtual int deposit(double x);

};


#endif //TASK2_BANKAPP_BANKACCOUNT_H
