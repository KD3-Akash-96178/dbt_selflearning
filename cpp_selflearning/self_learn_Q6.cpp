#include<iostream>
using namespace std;
class balaceInsufficintException
{
private:
    string message;

public:
    balaceInsufficintException(string message)
    {
        this->message = message;
    }
    string getMessage(void)
    {
        return this->message;
    }
};
class BankAccount{
    private:
    string accountnumber;
    string accountHolderName;
    double balance;
    public:
    BankAccount(void):balance(5000),accountnumber("12345678910"),accountHolderName("Pratham Tayade"){
        cout<<"Name : "<<accountHolderName<<endl;
        cout<<"Account Number: "<<accountnumber<<endl;
    }
    void deposite(){
        double deposite;
        cout<<"Enter the amount to deposite: "<<endl;
        cin>>deposite;
        
        balance =balance + deposite;

    }
    void checkBalance(){
        cout<<"Available balance: "<<balance<<endl;
    }
    void withdraw(){
        double withdraw;
        cout<<"Enter the amount to withdraw : "<<endl;
        cin>>withdraw;
        if(balance<withdraw){
        throw balaceInsufficintException("Balance is insufficent");
        }
        balance=balance-withdraw;

    }
};
int main(){
    BankAccount bank;
    try{

    
    bank.deposite();
    bank.checkBalance();
    bank.withdraw();
    bank.checkBalance();

    }
    catch(balaceInsufficintException ex){
        cout<<ex.getMessage()<<endl;
    }

}