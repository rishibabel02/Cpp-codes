#include<iostream>
#include<algorithm>
using namespace std;

void maxoutcome();

int main(){
    int t;
    cin>>t;
    while(t--){
        maxoutcome();
    }
    return 0;
}

void maxoutcome(){
    int n;
    cin>>n;
    int arr[2*n];
    for(int i=0; i<(2*n); i++){
        cin>>arr[i];
    }
    sort(arr, arr+(2*n));
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[2*i];
    }
    cout<<sum<<endl;
}