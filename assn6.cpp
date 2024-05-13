// A business house has several offices in different countries; they want to lease phone lines to connect them 
// with each other and the phone company charges different rent to connect different pairs of cities. (Create & 
// display of Graph). Solve the problem using Prim’s algorithm.
#include<bits/stdc++.h>
using namespace std;

class graph{
    int n;
    // gnode head[20];
    int cost[20][20];
    public:
        void getdata();
        void getdist();
        void display();
        void prims();
};

void graph :: getdata(){
    cout<<"Enter no. of nodes in the graph: ";
    cin>>n;
    
    int i,j;
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cost[i][j]=9999;
        }
    }
}

void graph :: getdist(){
    cout<<"Enter the rent to connect different pairs of cities in a matrix pattern"<<endl;
    char ch;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
		{
			cout<<"do you have an edge between"<<i<<"and"<<j<<"(y/n):";
			cin>>ch;
			if(ch=='y'){
				cout<<"Enter the cost";
				cin>>cost[i][j];
				cost[j][i]=cost[i][j];
			}
		}
	}
}

void graph :: display(){
    for(int i=0; i<n; i++){
        cout<<"\t"<<i;
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<"\t";
        for(int j=0; j<n; j++){
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void graph::prims()
{
    int start_v;
    cout<<"Enter the node to start traversing: ";
    cin>>start_v;
	int nearest[100];
	nearest[start_v]=-1;
	for(int i=0;i<n;i++)
	{
		if(i!=start_v)
		{
			nearest[i]=start_v;
		}
	}
	int r=0,i,k,min;
	int j=0;
	int t[100][3];
	int mincost=0;
	for(i=1;i<n;i++){
		min=999;
		for(k=0;k<n;k++){
			if(nearest[k]!=-1&&cost[k][nearest[k]]<min)
			{
				j=k;
				min=cost[k][nearest[k]];
			}
		}
		t[r][0]=j;
		t[r][1]=nearest[j];
		t[r][2]=min;
		r=r+1;
		
		mincost=mincost+cost[j][nearest[j]];
		nearest[j]=-1;
		for(k=0;k<n;k++){
			if(nearest[k]!=-1&&(cost[k][nearest[k]])>cost[k][j])
			{
				nearest[k]=j;
			}
		}
	}
    cout<<endl<<"n1\tn2\tdistance"<<endl;
	for(i=0;i<r;i++){
		for(j=0;j<3;j++){
			cout<<t[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Minimum cost to traverse is :"<<mincost<<endl;
}

int main(){
    graph g1;
    g1.getdata();
    g1.getdist();
    g1.display();
    g1.prims();

    return 0;
}