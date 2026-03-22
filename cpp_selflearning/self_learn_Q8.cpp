#include<iostream>
using namespace std;
class Programmer

{   
    public:
    
    Programmer(){
    cout<<"Programmer constructor calling "<<endl;
}
    void work(){
        cout<<"work function in Programmer "<<endl;
    }

};
class Teacher{
    public:
    Teacher(){
        cout<<"Teacher constructor calling "<<endl;
    }
    
     void work(){
        cout<<"work function in Teacher "<<endl;
    }

};

class ProgrammingTeacher : public Programmer,Teacher{
    public:
    ProgrammingTeacher(){
        
        cout<<"ProgrammingTeacher constructor calling "<<endl;

    }
      
    
};
int main(){
    ProgrammingTeacher pt1;
//    pt1.work();  ambiguity error
    pt1.Programmer::work();



}