#include<iostream>
#include<cstring>
using namespace std;

class Payment
{
    private:
    double amount;

    public:
    Payment():amount(0.0)
    {  }
    Payment(double amount):amount(amount)
    {  }
    virtual void makePayment(double amount)
    {
        cout<<"Amount : "<<amount<<endl;
    }
};
class CreditCard : public Payment
{
    public:
    void makePayment(double amount)
    {
        cout<<"Credit card Payement : "<<amount<<endl;
        cout<<"Payment Successful"<<endl;
    }

};
class UPI : public Payment
{
    public:
    void makePayment(double amount)
    {
        cout<<"UPI Payment : "<<amount<<endl;
        cout<<"Payment Successful"<<endl;
    }
};
class Cash : public Payment
{
    public:
    void makePayment(double amount)
    {
        cout<<"Cash payment : "<<amount<<endl;
        cout<<"Payment Successful"<<endl;
    }
};
class PaymentFactory
{
    public:
    static Payment* create(char* mode)
    {
        if(strcmp(mode, "Credit")==0)
            return new CreditCard();

        else if(strcmp(mode, "UPI")==0)
            return new UPI();

        else if(strcmp(mode, "Cash")==0)
            return new Cash();

        else 
            return NULL;
    }

};
int main()
{
    char mode[20];
    double amount;

    cout<<"Enter payment mode (Credit / UPI / Cash ) : ";
    cin>>mode;

    Payment *p=PaymentFactory::create(mode);
    
    if(p==NULL)
    {
        cout<<"Invalid Amount "<<endl;
        return 0;
    }

    cout<<"Enter amount : ";
    cin>>amount;

    p->makePayment(amount);

    return 0;
}