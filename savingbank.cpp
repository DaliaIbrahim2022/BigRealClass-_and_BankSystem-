
#include "BankAccount.h"
#include "client.h"
#include "savingbank.h"


SavingBankA::SavingBankA(string AID, double balance, double minBalance) {
    this->ID =AID ;
    this->balance = balance;
    this->minimumBalance = minBalance;

}

void SavingBankA::setMinimumBalance(double minimumB) {
    this->minimumBalance = minimumB;

}

double SavingBankA::getMinimumBalance() {
    return this->minimumBalance;
}

SavingBankA::SavingBankA() {
    this->minimumBalance = 1000;

}

bool SavingBankA::isSaving() {
    return true;
}


