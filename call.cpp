#include<iostream>
using namespace std;

int sum(int a, int b){
int c = a+b;
return c;

}
//this will not swap a and  b 
void swap(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}

//call by reference using ptr.
void swap_ptr(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//call by reference using  C++ reference variables.
 
void swap_ref_variable(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
    // return a;  // int & 
}

int main(){
    int a = 5,b=4;
    // cout<<"Sum of 4 and 5 is "<<sum(4,5);
    cout<<"The value of a is: "<<a<<" and the value of b is:"<<b<<endl;
    //this will not swap a and  b 
    // swap(a,b);

    // swap_ptr(&a,&b);  //this will swap a and b using ptr.

    swap_ref_variable(a,b); //this will swap using refernce variable

    // swap_ref_variable(a,b) = 766; //this will swap using refernce variable and change the value of a to 766

    cout<<"The value of a is: "<<a<<" and the value of b is:"<<b<<endl;
    return 0;
}