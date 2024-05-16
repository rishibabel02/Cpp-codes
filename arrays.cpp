#include <iostream>
using namespace std;

int main()
{
    int marks[] = {23, 45, 56, 9};
    // cout<<marks[0]<<endl;
    // cout<<marks[1]<<endl;
    // cout<<marks[2]<<endl;
    // cout<<marks[3]<<endl;

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "The value of marks " << i << " is " << marks[i] << endl;
    // }

    int *p = marks;
    cout<<*(p++)<<endl;
    cout<<*p<<endl;
    cout<<*(++p);
    // cout<<"The value of marks[0] is "<<*p<<endl;
    // cout<<"The value of marks[1] is "<<*p+1<<endl;
    // cout<<"The value of marks[2] is "<<*p+2<<endl;
    // cout<<"The value of marks[3] is "<<*p+3<<endl;
    return 0;
}

