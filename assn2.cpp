#include<bits/stdc++.h>
using namespace std;

class treenode
{
    int data;
    treenode *left;
    treenode *right;
    friend class tree;
};
class tree{
      treenode *root;


public:
    tree();
    void create_nr();
    void inorder_nr();
    void preorder_nr();
    void postorder_nr();

 
};
tree:: tree()
{
    root = NULL;
}
class stck{
    int top;
    treenode *data[30];
    public:
        stck()
        {
            top = -1;
        }
    void push(treenode *temp);
        treenode *pop();
        int empty();
        friend class tree;
    
    };
void stck:: push(treenode *temp)
{   
    if(top<30)
    {
        top++;
        data[top] = temp;
    }
    else{
        cout<<"Overflow!!"<<endl;
    }
}

treenode *stck::pop()
{
    if(empty()!=1)
    {
    treenode *temp = data[top];
    top--;
    return temp;
    }
    else{
        cout<<"Underflow!!"<<endl;
    }
}

int stck::empty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void tree::inorder_nr()
{    
    stck s;
    treenode *temp = root;
    while(1)
    {
        while(temp!=NULL){
        s.push(temp);
        temp = temp->left;
        }
    
    if (s.empty())
    {
        break;
    }
    temp = s.pop();
    cout<<temp->data<<" ";
    temp = temp->right;
    }

}

void tree::preorder_nr()
{    
    stck s;
    treenode *temp = root;
    while(1)
    {
        while(temp!=NULL){
        cout<<temp->data<<" ";
        s.push(temp);
        temp = temp->left;
        }
    
    if (s.empty())
    {
        break;
    }
    temp = s.pop();
    temp = temp->right;
    }

}

void tree::postorder_nr()
{    
    stck s;
    treenode *temp = root;
    while(1)
    {
        while(temp!=NULL){
       
        s.push(temp);
        temp = temp->left;
        }
    if(s.data[s.top]->right==NULL)
    {
        temp = s.pop();
        cout<<temp->data<<" ";
    }
    while((s.empty()!=1) && s.data[s.top]->right==temp)
    {
       temp = s.pop();
        cout<<temp->data<<" ";
    }
    if(s.empty()==1)
    {
        break;
    }

    temp = s.data[s.top]->right;
    }

}

void tree::create_nr()
{
    if (root == NULL)
    {
        root = new treenode;

        cout << "Enter the Value of root Node: \n";
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
    }

    char dat;
    do
    {
        treenode *temp = root;
        int flag = 0;
        treenode *curr = new treenode;
        cout << "Enter the data for the next node :\n";
        cin >> curr->data;
        curr->left = NULL;
        curr->right = NULL;

        while (flag == 0)
        {
            char ch;
            cout << "Would you like to add more nodes in the left or right (l/r) of  " << temp->data << "\n";
            cin >> ch;
            if (ch == 'l')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }

        cout << "Do you want to add more data? (y/n)\n";
        cin >> dat;
    } while (dat == 'y');
}


int main()
{
    tree bt;
    bt.create_nr();

    while(1){
    cout << "Which Traversing Method Would You Like to Choose?" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "1.Inorder Traversal:\n";
        bt.inorder_nr();
        break;

    case 2:
        cout << "\n 2.Preorder Traversal:\n";
        bt.preorder_nr();
        break;

    case 3:
        cout << "\n 3.Postorder Traversal:\n";
        bt.postorder_nr();
        break;

    case 4:
        exit(0);
    }
    }
    return 0;
}
