#include<iostream>
using namespace std;
class sswap
{

    public:
    void swapByValue(int a, int b)
    {
        int temp = a;
        a=b;
        b=temp;

    }
    void swapByReference(int &a, int &b)
    {
        int temp = a;
        a=b;
        b=temp;
    }

};
int main()
{
    int a = 10;
    int b = 20;

    cout<<"before swapByValue : ";
    cout<<a<<" "<<b<<endl;

    sswap s;
    s.swapByValue(a, b);
    cout<<"after swapByValue : ";
    cout<<a<<" "<<b<<endl;
    sswap s1;
    s1.swapByReference(a, b);
    cout<<"after swapByReference : ";
    cout<<a<<" "<<b<<endl;
    return 0;
};