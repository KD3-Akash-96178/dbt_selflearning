#include<iostream>
using namespace std;

class Product
{
    private:
    string title;
    double price;
    public:
    Product():title(""), price(0.0)
    { }
    Product(string title, double price):title(title), price(price)
    {  }

    virtual void accept()
    {
        cout<<"Enter title : ";
        cin>>title;
        cout<<"Enter price : ";
        cin>>price;
    }
    virtual void display()
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }
};
class Book : public Product
{
    private:
    int pages;

    public:
    Book():pages(0)
    {  }
    Book(string title, double price, int pages):Product(title,price), pages(pages)
    {  }
    void accept()
    {
        Product::accept();
        cout<<"Enter pages : ";
        cin>>pages;
    }
    void display()
    {
        Product::display();
        cout<<"Pages : "<<pages<<endl;
    }
};
class Tape : public Product
{
    private:
    int playTime;

    public:
    Tape():playTime(0)
    {  }
    Tape(string title, double price, int playTime):Product(title,price), playTime(playTime)
    {  }

    void accept()
    {
        Product::accept();
        cout<<"Enter PlayTime : ";
        cin>>playTime;
    }
    void display()
    {
        Product::display();
        cout<<"PlayTime : "<<playTime<<endl;
    }
}; 
int menuList()
{
    int choice;
    
    return choice;
}

int main()
{
    int choice;
    int i;
    Product *arr[5];
    for(int i = 0; i<5; i++){
        cout<<"0.Exit."<<endl;
        cout<<"1.Book."<<endl;
        cout<<"2.Tape."<<endl;
        cout<<"Enter choice : ";
        cin>>choice;       
        switch(choice)
        {    
            case 1:
                arr[i] = new Book;
                arr[i]->accept();
                arr[i]->display();
                break;
            case 2:
                arr[i] = new Tape;
                arr[i]->accept();
                arr[i]->display();
                break;          
        }
    }
}