#include<iostream>
using namespace std;

 inline int product(int a , int b){
    // agar inline fn hai to static variable nhi bnana hai.
    // static int c = 0;  //this executes only once 
    // c =c+1;  //next time yaha se run hoga aur ye value retain ho jaegi
    // return a*b+c;
    return a*b;
}
 //jo bhi default argument hota hai usko hamesha extreme right me likhna hai (factor here ...)
float moneyReceived(int currentmoney , float factor=1.04)
{
    return currentmoney*factor;
}

// int strlen(const char *p)
// {
    // iska mtlb p ko is fn ke andar koi change nhi kr skta.
// }
int main(){
    int a,b;
    // cout<<"Enter the value of a and b :";
    // cin>>a>>b;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    // cout<<"THe product of a and b is :"<<product(a,b)<<endl;
    int money=100000;
    cout<<"If you have "<<money<<" In your bank, you will receive "<<moneyReceived(money)<<" Rs after 1 year ";
    return 0;
}