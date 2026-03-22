#include<iostream>
using namespace std;
class Students{
    public:
    int rollNo;
    int marks;

};
int main(){
    int n;
    cout<<"Enter the no. of Students: "<<endl;
    cin>>n;
    Students *arr = new Students[n];
    for(int i =1;i<=n;i++){
        cout<<"Enter the rollno of student "<<i<<" :"<<endl;
        cin>>arr[i].rollNo;
        cout<<"Enter the marks of student "<<i<<" : "<<endl;
        cin>>arr[i].marks;
    }
    // diaplay the records
    cout<<"----------------------"<<endl;
    for(int i =1;i<=n;i++){
        cout<<"Stduent "<<i<<endl;
        cout<<"Roll no: "<<arr[i].rollNo<<endl;
        cout<<"Marks : "<<arr[i].marks<<endl;
    }
    //display highest marks in the class
    cout<<"----------------------"<<endl;
    int high = 0;
    for(int i=1;i<=n;i++){
        if(arr[i].marks>high){
            high=arr[i].marks;
        }
    }
    cout<<"Highest marks :  "<<high<<endl;
    delete[] arr;
    return 0;



}