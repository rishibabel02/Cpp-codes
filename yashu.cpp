#include<bits/stdc++.h>
using namespace std;

class gnode{
    string user;
    int vertex;
    gnode* next;
    friend class graph;
    // friend class queueee;
};

class graph{
    gnode* head[20];
    int visited[20];
    int n; // no of nodes
    public:
        graph(){
            // int n;
            cout<<"Enter the no. of vertices: ";
            cin>>n;
            // int n=nodes;
            for(int i=0; i<n; i++){
                head[i]=new gnode;
                head[i]->vertex = i;
                cout<<"Enter username: ";
                cin>>head[i]->user;
                head[i]->next = NULL;
            }
        }
        void create();
        void dfs();
        void dfs(int);
        void dfs_nr(int);
        void bfs(int v);
        void display();
};

class queueee{
    int front;
    int rear;
    int q[20];
    public:
        queueee(){
            front=rear=-1;
        }
        void enqueue(int n);
        int dequeuee();
        int full(){
            if(rear==19){
                return 1;
            }
            return 0;
        }
        int empty(){
            if(front==rear || (front==-1 && rear==-1)){
                return 1;
            }
            return 0;
        }
    friend class graph;
};

void queueee::enqueue(int n){
    if(full()){
        cout<<"Queue is full"<<endl;
    }
    rear++;
    q[rear]=n;
}

int queueee::dequeuee(){
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    // gnode*temp=new gnode;
    front++;
    int temp=q[front];
    return temp;
}

class stackk{
    int top;
    int data[20];
    public:
        stackk(){
            top=-1;
        }
        void push(int temp);
        int pop();
        int empty();
        // friend class graph;
};

void stackk:: push(int temp){
    if(top<20){
        top++;
        data[top]=temp;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}

int stackk::pop(){
    if(!empty()){
        int temp=data[top];
        top--;
        return temp;
    }
    else{
        cout<<"Stack Underflow"<<endl;
    }
}

int stackk::empty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void graph::create(){
    char choice;
    for(int i=0; i<n; i++){
        gnode* temp=head[i];
        cout<<endl<<"Adjacency list for "<<head[i]->user<<" vertex"<<endl;
        do{
            int v;
            cout<<"Enter adjacent vertex of "<<head[i]->user<<": ";
            cin>>v;

            if(v==i){
                cout<<"Self loop are not allowed"<<endl;
            }
            else{
                gnode* curr=new gnode;
                curr->next = NULL;
                curr->vertex = v;
                temp->next=curr;
                temp=temp->next;
            }
            cout<<"Do you want to add more node(y/n):";
            cin>>choice;
        }while(choice=='y');
    }
}

void graph::display() {
    gnode *temp;
    // cout<<nodes;
    for (int i = 0; i < n; i++) {
        temp = head[i];
        // cout<<temp->vertex<<" ";
        cout << "Adjacency list for user " << head[i]->user << ": ";
        while (temp != NULL) {
            // cout << temp->user <<"("<< temp->vertex<< ")-> ";
            cout <<"("<< temp->vertex<< ")-> ";
            temp = temp->next;
        }
        cout << "end" << endl;
    }
}

void graph::dfs(){
    // visited[nodes];
    // int n=nodes;
    int v;
    for(int i=0; i<n; i++){
        visited[i]=0;
    } 
    cout<<"Enter the node vertex to start traversing: ";
    cin>>v;
    dfs(v);
}

void graph::dfs(int v){
    // cout<<v<<" ";
    cout<<head[v]->user<<" ";
    visited[v]=1;   
    int w;
    gnode* temp=head[v];
    temp=head[v]->next;
    while(temp!=NULL){
        w=temp->vertex;
        if(!visited[w]){
            dfs(w);
        }
        temp=temp->next;
    }
}

void graph:: dfs_nr(int v){
    for(int i=0; i<n; i++){
        visited[i]=0;
    }  
    // stack<int> st;
    stackk st;
    st.push(v);
    visited[v]=1;
    do{
        // v = st.top();
        v = st.pop();
        cout<<head[v]->user<<" ";
        
        gnode* temp = head[v]->next;
        while(temp != NULL){
            int w=temp->vertex;
            if(!visited[w]){
                st.push(w);
                visited[w]=1;
            }
            temp=temp->next;
        }
    }while(!st.empty());
}

void graph::bfs(int v){
    // int w=0;
    for(int i=0; i<n; i++){
        visited[i]=0;
    }
    queue<int> q;
    q.push(v);
    visited[v]=1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        cout<<head[v]->user<<" ";

        gnode* temp = head[v]->next;
        while(temp != NULL){
            int w=temp->vertex;
            if(!visited[w]){
                q.push(w);
                visited[w]=1;
            }
            temp=temp->next;
        }
    }
}

int main(){
    graph g1;
    g1.create();
    while(1){
        cout<<"Which traversal you want to perform? "<<endl
            <<"1. Display Graph"<<endl
            <<"2. DFT (Recursive)"<<endl
            <<"3. DFT (Non-Recursive)"<<endl
            <<"4. BFT (Non-Recursive)"<<endl
            <<"5. Exit"<<endl;
        int choice;
        cin>>choice;
        int num;

        switch (choice)
        {
        case 1:
            g1.display();
            cout<<endl;
            break;

        case 2:
            g1.dfs();
            cout<<endl;
            break;
        
        case 3:
            cout<<"Enter the value of vertex ,you want to start traversing: ";
            cin>>num;
            g1.dfs_nr(num);
            cout<<endl;
            break;
        
        case 4:
            int num;
            cout<<"Enter the value of vertex ,you want to start traversing: ";
            cin>>num;
            g1.bfs(num);
            cout<<endl;
            break;

        case 5:
            exit(0);
        }
    }
    
    return 0;
}
