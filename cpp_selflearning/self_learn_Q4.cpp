#include<iostream>
using namespace std;
class Laptop{
    private:
    int brandId;
    double price;
    public:
    Laptop(void):brandId(1),price(50000){
        cout<<"Laptop constructor called !"<<endl;
    }
    ~Laptop(){
        cout<<"Laptop Destructor called !"<<endl;
     }
     void display(){
        cout<<"Brand Id : "<<brandId<<endl;
        cout<<"Price : "<<price<<endl;
     }


};
int main(){
    Laptop l1;
    l1.display();


}