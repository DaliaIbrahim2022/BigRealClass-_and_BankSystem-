#include "BankAccount.h"
#include "client.h"
#include "savinBank.h"


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

int SavingBankA::withdraw(double amount) {
        if (this->balance - amount >= minimumBalance) {
            this->balance -= amount;
            return 1;
        } else {
            return 0;
        }

}

int SavingBankA::deposit(double amount) {
    if (amount >= 100) {
        this->balance += amount;
        return 1;
    } else {
        return 0;
    }
}
