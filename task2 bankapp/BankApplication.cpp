#include "BankAccount.h"
#include "Client.h"
#include "savinBank.h"
#include "BankApplication.h"

#include <vector>
#include<iostream>

int BankApplication::menue()
{
    int choice;
    cout<<"Welcome to FCAI Banking Application \n";
    cout<<"1. Create a New Account\n";
    cout<<"2. List Clients and Accounts\n";
    cout<<"3. Withdraw Money\n";
    cout<<"4. Deposit Money\n";
    cout<<"please enter your choice: ";
    cin>>choice;
    return choice;
}

BankApplication::BankApplication() {

    int ch;
    do{
        ch=menue();
        switch (ch)
        {
            case 1:
                createAccount();
                break;
            case 2:
                listClientsAndAccounts();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                depositMoney();
                break;
            default:
                break;
        }
    }while(ch!=0);


}

void BankApplication::createAccount() {
    string Idn = to_string(vclient.size()+1);
    ID="FCAI_"+Idn;
    while(Idn.length() < 3) {
        Idn.insert(0, "0");
    }
    cout<<" Please enter your name : ";
    cin.ignore();
    string nam;
    getline(cin,nam);
    cout<<" Please enter your address : ";
    string addr;
    getline(cin,addr);
    cout<<"Please enter your phone : ";
    string p;
    cin>>p;
    cout<<"Please enter your account type (1) for Basic (2) for saving : ";
    int t;
    cin>>t;
    cout<<"Please enter your starting balance : ";
    double b;
    cin>>b;
    if(t == 1) {
        vclient.push_back(new Client(nam, addr, p, new BankAccount(ID, b)));
        accounts.push_back(new BankAccount(ID, b));
    }
    else if (t == 2) {
        int minn;
        cout << "Enter the minimum Balance" << endl;
        cin >> minn;
        if(b >= minn && minn != 0) {
            vclient.push_back(new Client(nam, addr, p, new SavingBankA(ID, b, minn)));
            accounts.push_back(new SavingBankA(ID, b, minn));
        } else if (b >= 1000 && minn == 0) {
            vclient.push_back(new Client(nam, addr, p, new SavingBankA(ID, b)));
            accounts.push_back(new SavingBankA(ID, b));
        }

    }
    else {
        cout << "Invalid Account Type" << endl;
    }
    cout << "An account was created with ID " << ID << " and Starting Balance " <<b<< endl;

}

void BankApplication::listClientsAndAccounts(){
    for(int i = 0; i < vclient.size(); i++) {
        cout << "name : " << vclient[i]->getName() << endl;
        cout << "Address : " << vclient[i]->getAddress() << endl;
        cout << "Phone : " << vclient[i]->getPhoneNum() << endl;
        cout << "AccId : " << accounts[i]->GetAccId() << endl;
        cout << "Balance : " << accounts[i]->GetBalance() << endl << endl;
    }
}

void BankApplication::withdrawMoney() {
    string userId;
    cout<<"please enter your account ID: ";
    cin>>userId;
    bool isvalid=0;

    for(long long i=0; i<accounts.size() ;i++){
        if(accounts[i]->GetAccId()==userId){
            isvalid=1;
            cout<<"your Balance: "<<accounts[i]->GetBalance()<<endl;
            double amountt;
            cout<<"Enter the amount of money to withdraw: ";
            cin>>amountt;
            if(accounts[i]->withdraw(amountt)==1){
                cout<<"Succesfully"<<endl;
                cout<<"Your account ID: " <<userId<<endl;
                cout<<"your new balance: "<<accounts[i]->GetBalance()<<endl;
            }
            else
                 cout<<"Sorry , you can't withdraw this amount of money"<<endl;

        }
    }
    if(!isvalid)
        cout<<"ID not exist."<<endl;

}

void BankApplication::depositMoney() {
    double amount;
    string userid;
    cout << "Please enter your account ID:";
    cin >> userid;
    bool isvalid = 0;

    for (long long i = 0; i < accounts.size(); i++) {
        if (accounts[i]->GetAccId() == userid) {
            isvalid = 1;
            cout << "your Balance: " << accounts[i]->GetBalance() << endl;
            cout << "Enter the amount of money to deposit: ";
            cin >> amount;
            if (accounts[i]->withdraw(amount) == 1) {
                cout << "Succesfully" << endl;
                cout << "Your account ID: " << userid << endl;
                cout << "your new balance: " << accounts[i]->GetBalance() << endl;
            } else
                cout << "Sorry , you can't deposit this amount of money , less than u can" << endl;

        }

    }
    if(!isvalid)
        cout<<"ID is not exist."<<endl;
}

