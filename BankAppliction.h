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
    bool isSaving();
    BankAccount();
    BankAccount(string accId ,double bal);
    void SetAccId(string accId);
    void SetBalance(double bal);
    double GetBalance();
//      string GetAccId();
    virtual int withdraw(double x);
    virtual int deposit(double x);
    string GetId();

//    string GetId();
//    virtual void  withdraw(double x);
//    virtual  void deposit(double x);
};
class SavingsBankAcount : public BankAccount
{
private:
    double minimumBalance=1000;
public:
  //  bool isSaving();
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

//    void SetName(string n);
//    void SetPhone(string p);
    BankAccount & GetAcc();
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
    BankApplication();
//    void Withdraw();
//    void Deposit();
    int menue();
    void CreatAccount();
    void listClientsAndAccounts();
//    void ListAccounts();
};

