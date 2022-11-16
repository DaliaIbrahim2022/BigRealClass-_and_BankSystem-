#ifndef NEW_FOLDER_6_BANKAPPLICTION_H
#define NEW_FOLDER_6_BANKAPPLICTION_H

#include <iostream>
#include <string>
#include <vector>
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
//      string GetAccId();
    virtual int withdraw(double x);
    virtual int deposit(double x);
    string GetId();

};


class SavingsBankAcount : public BankAccount
{
private:
    double minimumBalance=1000;
public:
    SavingsBankAcount();
    SavingsBankAcount(string accId ,double bal , double minbalance);
    void Setmin(double min);
    double Getmin();
//    void withdraw(double x);
//    void deposit(double x);
};


class Client{
private:
    string name;
    string phone;
    string address;
    BankAccount *acc;
    SavingsBankAcount *savings;
public:
    Client( string n , string a , string ph , BankAccount*acc);
    Client( string n , string a , string ph , SavingsBankAcount *saving);
    string getName();
    string getAddress();
    string getPhoneNum();
    BankAccount & GetAcc();
//    void SetName(string n);
//    void SetPhone(string p);
//    void Setaddres(string a);
//    void setacc( BankAccount *ptr);
//    void print();

};


class BankApplication
{
private:
    string type;
//    Client c;
    string ID="FCAI_";
    BankAccount b;
    vector<Client*>v;
    vector<BankAccount*>v2;
public:
    int menue();
    BankApplication();
//    void Withdraw();
//    void Deposit();
    void CreatAccount();
    void listClientsAndAccounts();
//    void ListAccounts();
};

#endif //NEW_FOLDER_6_BANKAPPLICTION_H