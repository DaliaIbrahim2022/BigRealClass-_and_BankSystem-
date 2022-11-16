#include "BankAppliction.h"
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

BankAccount &Client::GetAcc() {
    return *acc;
}

Client::Client(string n, string a, string ph, BankAccount* accountt) {
    this-> name=n;
    this-> address=a;
    this-> phone=ph;
    this->acc=accountt;
}

Client::Client(string n, string a, string ph, SavingsBankAcount *s) {
    this-> name=n;
    this->address=a;
    this->phone=ph;
    this->savings=s;
}

// ////////////////////////////////////////////////////////////////////////////////////////

BankAccount :: BankAccount()
{
    balance=0;
    ID="";

}
BankAccount :: BankAccount(string id, double bal)
{
    this->balance=bal;
    this->ID=id;

}

void BankAccount::SetAccId(string accId) {
    this->ID= accId;
}

string BankAccount :: GetId() {
    return (ID + to_string(cnt++));
}


void BankAccount :: SetBalance(double x){
    this-> balance=x;
}



double BankAccount :: GetBalance(){
    return balance;
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

bool BankAccount::isSaving() {
    return true;
}

SavingsBankAcount::SavingsBankAcount(string accId, double bal, double minbalance) {
    this->ID=accId;
    this->balance=bal;
    this->minimumBalance=minbalance;

}
void BankApplication::CreatAccount() {

    SavingsBankAcount s;
    cout<<" Please enter your name : ";
    string nam;
    cin.ignore();
    getline(cin,nam);
    cout<<" Please enter your address : ";
    string addr;
    getline(cin,addr);
    cout<<"Please enter your phone : ";
    string p;
    cin>>p;
    cout<<"Please enter your account type : ";
    string t;
    cin>>t;
    type=t;
    cout<<" Please enter your balance : ";
    double balnce;
    cin>>balnce;
    if(type=="Basic")
    {
        v.push_back(new Client(nam, addr, p, new BankAccount(ID, balnce )));
        v2.push_back(new BankAccount(ID, balnce));
    }
    else if(type == "saving")
    {
        cout<<"Please enter your minimum balance : ";
        double minbal;
        cin>>minbal;
        v.push_back(new Client(nam, addr, p, new SavingsBankAcount(ID, balnce, minbal)));
        v2.push_back(new SavingsBankAcount(ID, balnce, minbal));

    }
    if(type=="Basic")
        cout<<"An account was created with ID " <<b.GetId()<< " and Starting Balance "<< b.GetBalance()<<" L.E.";
    else
        cout<<"An account was created with ID " <<b.GetId()<< " and Starting Balance "<<s.Getmin()<<" L.E.";
}
void  SavingsBankAcount :: Setmin(double min){
    minimumBalance=min;
}

double  SavingsBankAcount :: Getmin(){
    return minimumBalance ;
}

SavingsBankAcount::SavingsBankAcount() {
    minimumBalance=0;

}

//bool SavingsBankAcount::isSaving() {
//    return true;
//}
//
//
//void BankApplication:: ListAccounts()
//{
//    for (auto i: v)
//    {
//        i.print();
//        cout<<endl;
//    }
//
//}
//void  BankAccount :: withdraw(double x)
//{
//    if(balance - x >= 0)
//        balance-=x;
//    else
//        cout<<"Sorry,Balance is not enough\n";
//
//}
//void  BankAccount :: deposit(double x)
//{
//    balance+=x;
//
//}

BankApplication::BankApplication(){
    int ch;
    do{
        ch=menue();
        switch (ch)
        {
            case 1:
                CreatAccount();
                break;
            case 2:
                listClientsAndAccounts();
                break;
            case 3:
//                Withdraw();
                break;
            case 4:
//                Deposit();
                break;
            default:
                break;
        }
    }while(ch!=0);

}
string Client::getName(){
    return this->name;
}
string Client::getAddress(){
    return this->address;
}
string Client::getPhoneNum(){
    return this->phone;
}

void BankApplication::listClientsAndAccounts(){
    for(int i = 0; i < v.size(); i++) {
        cout << "name : " << v[i]->getName() << endl;
        cout << "Address : " << v[i]->getAddress() << endl;
        cout << "Phone : " << v[i]->getPhoneNum() << endl;
        cout << "AccId : " << v2[i]->GetId() << endl;
        cout << "Acc Type : ";
       v2[i]->isSaving() ? cout << "Saving" << endl : cout << "Basic" << endl;
        cout << "Balance : " << v2[i]->GetBalance() << endl << endl;
    }
}

//void BankApplication::Withdraw() {
//    cout<<"Please enter your ID : ";
//    string id;
//    cin>>id;
//    int amount;
//    cin>>amount;
//    cout<<"Please enter the amount you want to withdraw : ";
//    double x;
//    cin>>x;
//    for (auto i: v2)
//    {
//
//    }
//
//}

//void BankApplication::Deposit() {
//    cout<<"Please enter your ID : ";
//    string id;
//    cin>>id;
//
//    cout<<"Please enter the amount you want to deposit : ";
//    double x;
//    cin>>x;
//    for (auto i: v2)
//    {
//
//    }
//
//}


//void Client :: print()
//{
//    cout << "Name : " << name <<endl<< "Address : " << address <<endl<< "Phone : " << phone<<"\n";
//}
//
//
//void Client :: setacc( BankAccount *ptr)
//{
//    acc=ptr;
//}


//void Client::Setaddres(string a) {
//    address=a;
//
//}


// //////////////////////////////////////////////////////////////////



//void  BankAccount :: withdraw(double x)
//{
//    if(balance - x >= 0)
//        balance-=x;
//    else
//        cout<<"Sorry,Balance is not enough\n";
//
//}
//void  BankAccount :: deposit(double x)
//{
//    balance+=x;
//
//}

//SavingsBankAcount :: SavingsBankAcount(){}

//void  SavingsBankAcount :: withdraw( double x)
//{
//
//    BankAccount :: withdraw(x);
//    if(x>=1000)
//        balance+=x;
//
//}
//void  SavingsBankAcount :: deposit( double x) {
//    if (x >= 100)
//        balance -= x;
//    else
//        cout << "It is not allowed to deposit a quantity less than 100";
//
//}

//SavingsBankAcount::SavingsBankAcount() {
//
//}