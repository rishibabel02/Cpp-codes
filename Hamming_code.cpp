#include <bits/stdc++.h>
using namespace std;

int redundant_bits(int x)
{
    int y = 0;
    int i = 0;
    while (1)
    {
        if (pow(2, i) < x + y + 1)
            y++;
        else
        {
            break;
        }
        i++;
    }
    return y;
}
int main()
{
    int d;
    cout << "Enter the number of data bits: " << endl;
    cin >> d;

    int r = redundant_bits(d);
    cout <<"The no of redundant bits are "<< r << endl;

    int sent_bits[d + r];
    int ctr = 0;
    cout << "Enter data bits that are to be sent:" << endl;
    for (int i = 0; i < d + r; i++)
    {
        if ((i + 1) == pow(2, ctr))
        {
            ctr++;
            continue;
        }
        cin >> sent_bits[i];
    }

    int received_bits[d+r];
    cout<<"Enter the received data bits:"<<endl;
     for (int i = 0; i < d + r; i++)
    {
        if ((i + 1) == pow(2, ctr))
        {
            ctr++;
            continue;
        }
        cin >> received_bits[i];
    }


    return 0;
}