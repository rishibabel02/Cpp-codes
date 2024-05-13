#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    string word, meaning;
    node* left;
    node* right;
    public :
        friend class AVLtree;
};

class AVLtree{
    node* root;
    public:
        int height(node* );
        int diff(node* );
        node* rr(node* );
        node* ll(node* );
        node* lr(node* );
        node* rl(node* );
        node* balance(node* );
        node* insert2(node* ,node* );
        node* insert1();
        // void display(node* ,int );
        void inorder_r(node* );
        AVLtree(){
            root = NULL;
        }
        void BFS();
};

class queueee{
    int front;
    int rear;
    node* q[30];
    public:
        queueee(){
            front=rear=-1;
        }
        void enqueue(node*next);
        node*dequeue();
        int full(){
            if(rear==29){
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
    friend class AVLtree;
};

void queueee::enqueue(node*next){
    if(full()==1){
        cout<<"Queue is full"<<endl;
    }
    rear++;
    q[rear]=next;
}

node*queueee::dequeue(){
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return NULL;
    }
    // node*temp=new node;
    front++;
    node *temp=q[front];
    return temp;
}


node* AVLtree::ll(node* parent){
    node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

node* AVLtree::rr(node* parent){
    node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

node* AVLtree::lr(node* parent){
    node* temp = parent->left;
    parent->left = rr(temp); //calling rr rotation
    return ll(parent); 
}

node* AVLtree::rl(node* parent){
    node* temp = parent->right;
    parent->right = ll(temp); //calling ll rotation
    return rr(parent); 
}

int AVLtree::diff(node* temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

int AVLtree::height(node* temp){
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

node* AVLtree:: balance(node* temp){
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll(temp);
        else
            temp = lr(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl(temp);
        else
            temp = rr(temp);
    }
    return temp;
}   

node* AVLtree::insert1(){ //workhorse to insert{
    char ch;
    do
    {
        node* temp;
        temp=new node;
        temp->left=NULL;
        temp->right=NULL;
        cout<<"Enter word and it's meaning: ";
        cin>>temp->word>>temp->meaning;
        root=insert2(root, temp);
        cout<<"Do you want to insert more values (y/n)?: ";
        cin>>ch;
    }while(ch == 'y');

    cout<<endl;
    cout<<"Inorder Traversal:"<<endl;
    cout<<"Inorder traversal gives sorted array"<<endl;
    inorder_r(root);
    cout<<endl;
    cout<<"Level Wise Display"<<endl;
    BFS();
}

node* AVLtree:: insert2(node *root,node *temp){
    if (root == NULL)
    {
        root = new node;
        root->word = temp->word;
        root->meaning= temp->meaning;
        root->left = NULL;
        root->right = NULL;
      
       // inorder_r(root);
        return root;
    }
    else if (temp->word < root->word)
    {
        root->left = insert2(root->left, temp);
        root = balance (root);
    }
    else if (temp->word >= root->word)
    {
        root->right = insert2(root->right, temp);
        root = balance (root);
    }
    return root;
}

// void AVLtree::display(node* ptr, int level){ // consider level =1
//     if (ptr != NULL) {
//         display(ptr->right, level + 1);
//         printf("\n");
        
//         if (ptr == root)
//             cout << "Root -> ";
        
//         for (int i = 0; i < level && ptr != root; i++)
//             cout << " ";
        
//         cout << ptr->data;
//         display(ptr->left, level + 1);
//     }
// }

void AVLtree::inorder_r(node *temp){
    if (temp != NULL){
        inorder_r(temp->left);
        cout << temp->word << "->" << temp->meaning << endl;
        inorder_r(temp->right);
    }
}

void AVLtree::BFS(){
    int p=1;
    int r=0;
    queueee line;
    node*temp = root;
    line.enqueue(temp);

    while(!line.empty()){
        for(int i=0; i<p; i++){
            temp=line.dequeue();
            cout<<temp->word<<"("<<temp->meaning<<") ";
            if(temp->left!=NULL){
                line.enqueue(temp->left);
                r++;
            }
            if(temp->right!=NULL){
                line.enqueue(temp->right);
                r++;
            }
        }
        cout<<endl;
        p=r;
        r=0;
    }
}


int main(){
    AVLtree dict;
    dict.insert1();
    
    return 0;
}