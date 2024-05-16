#include <bits/stdc++.h>
using namespace std;

bool gifts(int budget)
{
    int current = 1;
    int total = budget;
    
    for(int i =1; i<=7; i++)
    {
        if(current > total)
        {
            return false;
        }
        
        total = total - current;
        current *=2;
    }
    return true;
}
int main() {
     
    int testcases;
    cin>>testcases;
    
    int inputs[testcases];
   for(int a  = 0 ; a<testcases;a++)
   {
          
        cin>>inputs[a];
        
   }
    for(int a  = 0 ; a<testcases;a++)
    {
    if(gifts(inputs[a]))
    {
    cout<<"Yes"<<endl;
    }
    else
    {
    cout<<"No"<<endl;
    }
    }
    return 0;
}
