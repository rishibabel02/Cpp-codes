#include <bits/stdc++.h>
using namespace std;

class treenode
{
    string mean;
    string data;
    treenode *l;
    treenode *r;
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree()
    {
        root = NULL;
    }
    void create_bst();
    void bfs();
    void search();
    void search_nr();

    void mirror_r(){
        mirror_r(root);
        // bfs();
    }
    void mirror_r(treenode *root);
};

class qu
{
    int front, rear;
    treenode *q[30];

public:
    qu()
    {
        front = rear = -1;
    }
    void enq(treenode *next);
    treenode *deq();
    int isfull()
    {
        if (rear == 29)
        {
            return 1;
        }
        return 0;
    }
    int isempty()
    {
        if (front == rear || front == -1 && rear == -1)
        {
            return 1;
        }
        return 0;
    }

    friend class tree;
};
void tree::mirror_r(treenode *root){
    if(root!=NULL){
    treenode *temp;
    temp = root->l;
    root->l = root->r;
    root->r = temp;

    if(root->l!=NULL){
        mirror_r(root->l);
    }
    if(root->r!=NULL){
        mirror_r(root->r);
    }
    }
}
void tree::search_nr()
{
    int flag = 0;
    treenode *temp = root;
    string st;
    cout << "\n Enter string to be searched: ";
    cin >> st;

    while (temp != NULL)
    {
        if (st == temp->data)
        {
            flag = 1;
            cout << "Found"<<endl;
            break;
        }
        else if (st < temp->data)
        {
            temp = temp->l;
        }
        else
        {
            temp = temp->r;
        }

    }
        if(flag==0){
            cout<<"Not found"<<endl;
        }
}
void tree::create_bst()
{
    root = new treenode;
    root->l = NULL;
    root->r = NULL;
    cout << "ENter root data ";
    cin >> root->data;
    cout << "Enter root mean ";
    cin >> root->mean;

    char ch;
    do
    {
        treenode *temp = root;
        int flag = 0;
        treenode *curr = new treenode;
        curr->l = NULL;
        curr->r = NULL;
        cout << "Enter curr data ";
        cin >> curr->data;
        cout << "ENter curr mean ";
        cin >> curr->mean;
        while (flag == 0)
        {
            if (curr->data < temp->data)
            {
                if (temp->l == NULL)
                {
                    temp->l = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->l;
                }
            }
            else
            {
                if (temp->r == NULL)
                {
                    temp->r = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->r;
                }
            }
        }
        cout << "Want to add more? ";
        cin >> ch;

    } while (ch == 'y');
}

void qu::enq(treenode *next)
{
    if (isfull())
    {
        cout << "q is full";
    }
    rear++;
    q[rear] = next;
}

treenode *qu::deq()
{
    if (isempty())
    {
        cout << "q is empty";
    }
    front++;
    treenode *temp = q[front];
    return temp;
}

void tree::bfs()
{
    qu quee;
    treenode *temp = root;
    quee.enq(temp);
    while (!quee.isempty())
    {
        temp = quee.deq();
        cout << temp->data << "->";
        cout << temp->mean << " ";

        if (temp->l != NULL)
        {
            quee.enq(temp->l);
        }
        if (temp->r != NULL)
        {
            quee.enq(temp->r);
        }
    }
}
int main()
{
    tree bst;
    bst.create_bst();
    bst.bfs();
    bst.search_nr();
    cout<<"Mirror Rec"<<endl;
    bst.mirror_r();
    bst.bfs();

    return 0;
}