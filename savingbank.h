
#ifndef BANKZEFTT_SAVINGBANK_H
#define BANKZEFTT_SAVINGBANK_H
#include "BankAccount.h"
#include <iostream>
#include "client.h"


class SavingBankA : public BankAccount {
private:
    double minimumBalance;
    bool savings = true;
public:
    SavingBankA(string AID, double balance, double minBalance = 1000);
    SavingBankA();
    void setMinimumBalance(double minimumB);
    double getMinimumBalance();
//    int withdraw(double amount);
//    int deposit(double amount);
    virtual bool isSaving();
};


#endif //BANKZEFTT_SAVINGBANK_H
