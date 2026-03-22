#include<iostream>
using namespace std;
 namespace college{
    class Student{
        private:
        int rollNo;
        string name;
        public:
        Student(void):rollNo(0),name("abc"){}
        void setRollNo(int rollNo){
            this->rollNo=rollNo;
        }
        void setName(string name){
            this->name=name;
        }
        int getRollNo(void){
            return this->rollNo;
        }
        string getName(){
            return this->name;
        }


    };
    class Teacher{
         private:
        int courseId;
        string CourseName;
        public:
        Teacher(void):courseId(0),CourseName("xyz"){}
        void setCourseId(int courseId){
            this->courseId=courseId;
        }
        void setCourseName(string CourseName){
            this->CourseName=CourseName;
        }
        int getCourseId(void){
            return this->courseId;
        }
        string getCourseName(){
            return this->CourseName;
        }

    };
}
    int main(){
        using namespace college;
        college::Student s1;
        college::Teacher t1;
        s1.setName("Pratham");
        s1.setRollNo(101);
        cout<<"Name of student : "<<s1.getName()<<endl;
        cout<<"RollNo of student : "<<s1.getRollNo()<<endl;
        t1.setCourseId(201);
        t1.setCourseName("cpp programming ");
        cout<<"Course Id : "<<t1.getCourseId()<<endl;
        cout<<"Course Name : "<<t1.getCourseName()<<endl;
        return 0;

    }

