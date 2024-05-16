#include<iostream>
using namespace std;

int main(){
    int a =4;
    int *b = &a;
cout<<"The address of a is "<<b<<endl;
cout<<"The address of a is "<<&a<<endl;
cout<<"The Value at b  is "<<*b<<endl;

    int **c=&b;
    // pointer to pointer this store the add of pointer b
    cout<<"The address of b is "<<&b<<endl;
    cout<<"The address at b  is "<<c<<endl;
    cout<<"The value at c is "<<*c<<endl;
    cout<<"The value at address c  is "<<**c<<endl;

    // &  = address of operator  
    // * = dereference operator 
    return 0;
}