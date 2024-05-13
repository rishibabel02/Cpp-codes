#include <iostream>
using namespace std;

class graph
{
    int cost[30][30];
    int n;

public:
    void getdata();
    void getdist();
    void display();
    void prims();
};
void graph::getdata()
{
    // int n;
    cout << "ENter the no. of nodes: ";
    cin >> n;

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = 9999;
        }
    }
}

void graph::getdist()
{
    char ch;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            cout << "is there an edge b/w " << i << "and" << j ;
            cin >> ch;
            if (ch == 'y')
            {
                cout << "Enter the cost";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }
}

void graph::display(){
    int i,j;
    for(i = 0;i<n;i++){
        cout<<"\t"<<i;
    }
    cout<<endl;
    for(i = 0;i<n;i++){
        cout<<i<<"\t";
        for(j = 0;j<n;j++){
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;

    }
}

void graph::prims(){
    int start_v;
    cout<<"enter node to start traversing :";
    cin>>start_v;

    int nearest[100];
    nearest[start_v] = -1;
    for(int i = 0; i<n;i++){
        if(i!=start_v)
        {
            nearest[i] = start_v;
        }
    }

    int i,k,min,r=0;
    int j = 0;
    int t[100][3];
    int mincost = 0;

    for(i = 0;i<n;i++){
        min = 999;
        for(k = 0;k<n;k++){
            if(nearest[k]!=-1 && cost[k][nearest[k]] < min){
                j = k;
                min = cost[k][nearest[k]];
            }

        }
        t[r][0] = j;
        t[r][1] = nearest[j];
        t[r][2] = min;
        r =r+1;

        mincost = mincost + cost[j][nearest[j]];
        nearest[j] = -1;
        for(k = 0;k<n;k++){

        if(nearest[k]!=-1 && cost[k][nearest[k]] > cost[k][j]){
            nearest[k] = j;
        }
        }
    }
    cout<<endl<<"n1\tn2\tdistance"<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout<<t[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"minimum cost is :"<<mincost<<endl;

}
int main()
{
    graph g;
    g.getdata();
    g.getdist();
    g.display();
    g.prims();

    return 0;
}