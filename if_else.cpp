#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Your age is:"<<endl;
    cin>>age;

    // if(age<18){
    //     cout<<"You cant come";
    // }
    // else if(age==18){
    //     cout<<"Bacche ho abhi";
    // }
    // else{
    //     cout<<"AAjao yaar";
    // }

    switch(age){
        case 18:
        cout<<"You are 18";
        break;
        case 22:
        cout<<"You are 22";
        break;

    default:
    cout<<"No special cases";
    break;
    }
    return 0;
    }
    
