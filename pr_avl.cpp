#include <iostream>
using namespace std;

class node
{
    string word, mean;
    node *l;
    node *r;
    friend class avl;
};
class AVLtree
{
    node *root;

public:
    AVLtree()
    {
        root = NULL;
    }
    int height(node *);
    int diff(node *);
    node *rr(node *);
    node *ll(node *);
    node *lr(node *);
    node *rl(node *);
    node *balance(node *);
    node *insert2(node *, node *);
    node *insert1();
    void bfs();
    void inorder(node *);
};

class queueee
{
    int front;
    int rear;
    node *q[30];

public:
    queueee()
    {
        front = rear = -1;
    }
    void enqueue(node *next);
    node *dequeue();
    int full()
    {
        if (rear == 29)
        {
            return 1;
        }
        return 0;
    }
    int empty()
    {
        if (front == rear || (front == -1 && rear == -1))
        {
            return 1;
        }
        return 0;
    }
    friend class AVLtree;
};

void queueee::enqueue(node *next)
{
    if (full() == 1)
    {
        cout << "Queue is full" << endl;
    }
    rear++;
    q[rear] = next;
}

node *queueee::dequeue()
{
    if (empty())
    {
        cout << "Queue is empty" << endl;
        return NULL;
    }
    // node*temp=new node;
    front++;
    node *temp = q[front];
    return temp;
}

node *AVLtree::ll(node *parent)
{
    node *temp = parent->l;
    parent->l = temp->r;
    temp->r = parent;
    return temp;
}
node *AVLtree::rr(node *parent)
{
    node *temp = parent->r;
    parent->r = temp->l;
    temp->r = parent;
    return temp;
}
node *AVLtree::lr(node *parent)
{
    node *temp = parent->l;
    parent->l = rr(temp);
    return ll(parent);
}
node *AVLtree::rl(node *parent)
{
    node *temp = parent->r;
    parent->l = ll(temp);
    return rr(parent);
}

node *AVLtree::diff(node *temp)
{
    int l_height = height(temp->l);
    int r_height = height(temp->r);
    int balance_f = l_height - r_height;
    return balance_f;
}

node *AVLtree::height(node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->l);
        int r_height = height(temp->r);
        int max = max(l_height, r_height);
        h = max + 1;
    }
    return h;
}

node *AVLtree::balance(node *temp)
{
    int bal_f = diff(temp);
    if (bal_f > 1)
    {
        if ((temp->l) > 0)
        {
            temp = ll(temp);
        }
        else
        {
            temp = lr(temp);
        }
    }
    if (bal_f < 1)
    {
        if ((temp->l) > 0)
        {
            temp = rl(temp);
        }
        else
        {
            temp = rr(temp);
        }
    }
}

node *AVLtree::insert1(){
    char ch;
    do{
        node *temp = new node;
        temp->l = NULL;
        temp->r = NULL;

        cout<<"Enter the word and the meaning: "<<endl;
        cin>>temp->word>>temp->mean;

        root = insert2(root,temp);
        cout<<"More values? ";
        cin>>ch;

    }while(ch=='y');
    cout<<"Inorder traversal gives sorted array:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"level wise"<<endl;
    bfs();

}

node* AVLtree:: insert2(node *root,node *temp){
    if(root = NULL){
        root = new node;
        root->word = temp->word;
        root->mean = temp->mean;
        root->l = NULL;
        root->r = NULL;

        return root;
    }
    else if(temp->word < root->word){
        root->l = insert2(root->l , temp);
        root = balance(root);
        
    }
    else if(temp->word >= root->word){
        root->r = insert2(root->r , temp);
        root = balance(root);

    }
    return root;
}

void AVLtree::inorder(node *temp){
    if(temp!=NULL){
        inorder(temp->l);
        cout<<temp->word<<"-->"<<temp->mean;
        inorder(temp->r);
    }
}

void AVLtree::bfs()
{
    queueee qu;
    node *temp = root;
    qu.enqueue(temp);
    while (!qu.empty())
    {
        temp = qu.dequeue();
        cout << temp->word << "->";
        cout << temp->mean << " ";

        if (temp->l != NULL)
        {
            qu.enqueue(temp->l);
        }
        if (temp->r != NULL)
        {
            qu.enqueue(temp->r);
        }
    }
}
int main()
{
    AVLtree dict;
    dict.insert1();

    return 0;
}