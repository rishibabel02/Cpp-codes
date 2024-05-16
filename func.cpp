#include<iostream>
using namespace std;

// function prototype
// type function-name(arguments);
int sum(int a,int b);
// int sum(int ,int ); we can also write like this
void g();

int main(){
    int n1,n2;
    cout<<"ENter 1st number"<<endl;
    cin>>n1;
    cout<<"ENter 2nd number"<<endl;
    cin>>n2;
    // n1,n2 are actual parameters
    cout<<"The sum is "<<sum(n1,n2)<endl;
    g();
    return 0;
}

int sum(int a, int b)
{
    // a and b will be taking values from actual paramters n1 and n2 . So a and b are formal parameters
    int c = a+b;
    return c;
}

void g(){
    cout<<"Hello";
}