#include<iostream>
using namespace std;
class Math{
    public:
   inline int pow(int &a,int &n){
    int res=1;
    for(int i =1;i<=n;i++){
        res=res*a;
    }
    return res;

    } 
};
int main(){
    Math m1;
    int a=2,n =5;
   int res= m1.pow(a,n);
   cout<<a<<" to the power "<<n<<" : "<<res<<endl;
}