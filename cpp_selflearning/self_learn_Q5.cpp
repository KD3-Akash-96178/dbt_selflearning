#include<iostream>
using namespace std;
class String{
    public:
    size_t strlen(const char* str){
      if (str==NULL)
      {
        return 0;
      }
      size_t length =0;
      while (str[length]!='\0'){
        length++;
      }
    return length;
      
    }

};
int main(){
    String s1;
    char text[50];
    cout<<"Enter the string: ";
    cin.getline(text,sizeof(text));

    size_t length = s1.strlen(text);
    cout<<"Length of string is : "<<length<<endl;
    return 0;
}