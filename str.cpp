#include<iostream>
using namespace std;


typedef struct emp{
    int eid;
    char fav;
    float sal;
}ep;

// if you want to use only one of the below variables and then why not share the memory among all and for that we use union
union money
{
    int rice;
    char car ;
    float pounds;
};

int main(){
    //  struct emp rishi;
    // ep rishi;
    //  rishi.eid=1;
    //  rishi.fav= 'r';
    //  rishi.sal = 1200000;

    //  cout<<rishi.sal<<endl;
    //  cout<<rishi.fav<<endl;
    //  cout<<rishi.eid<<endl;

    // union money m1;
    // m1.rice = 50;
    // m1.car = 'c';
    // // cout<<m1.rice;
    // cout<<m1.car;


    enum Meal{breakfast, lunch, dinner };
    // cout<<breakfast<<endl;
    // cout<<lunch<<endl;
    // cout<<dinner;

    Meal m1= lunch;
    cout<<(m1==1);


    return 0;
}