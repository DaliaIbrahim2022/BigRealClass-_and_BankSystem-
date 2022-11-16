

#ifndef TASK2_BANKAPP_BANKAPPLICATION_H
#define TASK2_BANKAPP_BANKAPPLICATION_H

#include "BankAccount.h"
#include "Client.h"
#include <vector>
#include<iostream>

class BankApplication {
private:
    vector<BankAccount*> accounts;
    vector<Client*> vclient{};
    string ID;

public:
    int menue();
    BankApplication();
    void createAccount();
    void listClientsAndAccounts();
    void withdrawMoney();
    void depositMoney();
};


#endif //TASK2_BANKAPP_BANKAPPLICATION_H
