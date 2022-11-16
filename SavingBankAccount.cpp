#include "SavingBankAccount.h"

//SavingsBankAccount::SavingsBankAccount(string accoutID, double balance, double minBalance) {
//    this->ID =accoutID ;
//    this->balance = balance;
//    this->minimumBalance = minBalance;
//
//}

SavingsBankAccount::SavingsBankAccount() {
    this->minimumBalance = 1000;

}

void SavingsBankAccount::setMinimumBalance(double minimumBa) {
    this->minimumBalance = minimumBa;
}

double SavingsBankAccount::getMinimumBalance() {
    return this->minimumBalance;
}



