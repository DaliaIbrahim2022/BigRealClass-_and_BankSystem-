#include "BankAccount.h"

//constructor
BankAccount::BankAccount() {
    ID="";
    balance=0;
}

BankAccount::BankAccount(string accId, double bal) {
    this-> ID=accId;
    this-> balance=bal;

}

//setters
void BankAccount::SetAccId(string accId) {
    this->ID= accId;

}

void BankAccount::SetBalance(double bal) {
    this->balance=bal;
}

//getters
double BankAccount::GetBalance() {
    return balance;
}

string BankAccount::GetAccId() {
    return ID;
}

int BankAccount::withdraw(double x) {
    if(balance>=x)
    {
        balance-=x;
        return 1;
    }
    else
        return 0;
}

int BankAccount::deposit(double x) {
    if(x>0)
    {
        balance+=x;
        return 1;
    }
    else
        return 0;
}

