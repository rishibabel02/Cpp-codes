#include <iostream>
using namespace std;
class heap
{
    int stud[20];
    int n;

public:
    void add(int x);
    void heapup(int n);
    void display();
    void heapsort();
    void adjust(int n, int i);
};

void heap::add(int x)
{
    int j = 0;
    char ch;

    do
    {
        int el;
        cout << "ENter the marks of " << j + 1 << " th student: ";
        cin >> el;
        stud[j] = el;
        heapup(j + 1);
        j++;
    } while (j < x);
    n = j;
}

void heap::heapup(int n){
    int i = n;
    int el = stud[n-1];
    if(i!=1){
        while(i>0 && stud[(i/2)-1] < el){
            stud[i-1] = stud[(i/2)-1];
            i = i/2;

        }
        stud[i-1] = el;
    }
}

void heap::display(){
    cout<<"marks of students are ";
    for(int i = 0;i<n;i++){
        cout<<stud[i]<<" ";
    }
    cout<<endl;
}
void heap::heapsort(){
    int temp = n;
    while(temp >0 ){
        int t = stud[0];
        stud[0] = stud[temp-1];
        stud[temp-1] = t;
        temp--;
        adjust(temp-1 , 0);


    }
}


void heap::adjust(int n , int i){
    while(2*i + 1 <=n){
        int j = 2*i+1;
        if((j+1<=n) and (stud[j] < stud[j+1])){
            j=j+1;
        }
        if(stud[i]>= stud[j])
        break;
        else{
            int temp = stud[i];
            stud[i] = stud[j];
            stud[j] = temp;
            i = j;
        }
    }
}



int main()
{
    int x;
    cin>>x;
    heap marks;
    marks.add(x);
    marks.display();
    marks.heapsort();
    cout<<"sorted-->";
    marks.display();

    return 0;
}