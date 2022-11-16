#include "Client.h"


Client::Client(string n, string a, string p, BankAccount *_bank) {
    this-> name=n;
    this->address=a;
    this->phone=p;
    this->bankAcc=_bank;
}

string Client::getName() {
    return this->name;
}

string Client::getAddress() {
    return this->address;
}

string Client::getPhoneNum() {
    return this->phone;
}

Client::Client(string n, string a, string p, SavingBankA *bankAcc) {
    this->name = n;
    this->address = a;
    this->phone = p;
    this->bankAcc = bankAcc;

}