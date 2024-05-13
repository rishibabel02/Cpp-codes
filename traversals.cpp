#include <bits/stdc++.h>
using namespace std;

class treenode{
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
        void create_r();
        void create_r(treenode*);

        void inorder_nr();
        void preorder_nr();
        void postorder_nr();

        void inorder_r(){
            inorder_r(root);
        }
        void inorder_r(treenode *temp);

        void preorder_r(){
            preorder_r(root);
        }
        void preorder_r(treenode *temp);

        void postorder_r(){
            postorder_r(root);
        }
        void postorder_r(treenode *temp);
};

tree::tree(){
    root = NULL;
}

class stackk{
    int top;
    treenode*data[30];
    public:
        stackk(){
            top=-1;
        }
        void push(treenode*temp);
        treenode*pop();
        int empty();
        friend class tree;
};

void stackk:: push(treenode*temp){
    if(top<30){
        top++;
        data[top]=temp;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}

treenode* stackk::pop(){
    if(empty()!=1){
        treenode*temp=data[top];
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

void tree::create_nr(){
    if (root == NULL){
        root = new treenode;
        cout << "Enter the Value of root node: ";
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
    }

    char choice;
    do{
        treenode *temp = root;
        int flag = 0;
        treenode *curr = new treenode;
        cout << "Enter the data for the next node :\n";
        cin >> curr->data;
        curr->left = NULL;
        curr->right = NULL;

        while (flag == 0){
            char ch;
            cout<<"Would you like to add more nodes in the left or right (l/r) of "
                <<temp->data<<" ?"<<endl;
            cin >> ch;
            if (ch == 'l'){
                if (temp->left == NULL){
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else{
                if (temp->right == NULL){
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }

        cout<<"Do you want to add more data? (y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y');
}

void tree::create_r()
{
	if (root == NULL)
	{
		root = new treenode();
		cout<< "enter data for root : ";
		cin >> root->data;
		root->left =NULL;
		root->right=NULL;
	}
	create_r(root);
}

void tree::create_r(treenode*temp)
{
    char choice;
    cout<<"Enter the choice to add the data at left or right "<<temp->data<<endl;
    cin>>choice;
    if(choice=='l'|| choice=='L')
    {
        // treenode *temp = root;
        treenode *curr = new treenode();
        cout <<"enter data for curr: ";
        cin >> curr->data;
        curr->left =NULL;
        curr->right=NULL;
    
        temp->left=curr;
        create_r(curr);
    }
    cout<<"Enter the choice to add the data at left or right "<<temp->data<<endl;
    cin>>choice;
    if(choice=='r'|| choice=='R')
    {
        // treenode *temp = root;
        treenode *curr = new treenode();
        cout <<"enter data for curr: ";
        cin >> curr->data;
        curr->left =NULL;
        curr->right=NULL;
        
        temp->right=curr;
        create_r(curr);
    }
}

void tree::inorder_nr(){
    stackk s;
    treenode*temp=root;
    while(1){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()){
            break;
        }
        temp=s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

void tree::preorder_nr(){
    stackk s;
    treenode*temp=root;
    while(1){
        while(temp!=NULL){
            cout<<temp->data<<" ";
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()){
            break;
        }
        temp=s.pop();
        temp=temp->right;
    }
}

void tree::postorder_nr(){
    treenode*temp=root;
    stackk s;
    while(1){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        if(s.data[s.top]->right==NULL){
            temp=s.pop();
            cout<<temp->data<<" ";
        }
        while(s.empty()==0 && s.data[s.top]->right==temp){
            temp=s.pop();
            cout<<temp->data<<" ";
        }
        if(s.empty()){
            break;
        }
        temp=s.data[s.top]->right;
    }
}

void tree::inorder_r(treenode *temp){
    if (temp != NULL){
        inorder_r(temp->left);
        cout << temp->data << " ";
        inorder_r(temp->right);
    }
}

void tree::preorder_r(treenode *temp){
    if (temp != NULL){
        cout << temp->data << " ";
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void tree::postorder_r(treenode *temp){
    if (temp != NULL){
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout << temp->data << " ";
    }
}

int main()
{
    tree bt;
    int ch;
    cout<<"How do you want to create a binary tree(rec/non-rec)? "<<endl
        <<"1. recursive"<<endl
        <<"2. non-recursive"<<endl;
    cin>>ch;
    if(ch==1){
        bt.create_r();
    }
    else if(ch==2){
        bt.create_nr();
    }

    while(1){
        cout << "Which Traversing Method Would You Like to Choose?" << endl;
        cout << "1.Inorder Traversal(non-rec):"<<endl;
        cout << "2.Preorder Traversal(non-rec):"<<endl;
        cout << "3.Postorder Traversal(non-rec):"<<endl;
        cout << "4.Inorder Traversal(rec):"<<endl;
        cout << "5.Preorder Traversal(rec):"<<endl;
        cout << "6.Postorder Traversal(rec):"<<endl;
        cout << "7.Exit"<<endl;
        int n;
        cin >> n;
        switch (n)
        {
            case 1:
                bt.inorder_nr();
                cout<<endl;
                break;

            case 2:
                bt.preorder_nr();
                cout<<endl;
                break;

            case 3:
                bt.postorder_nr();
                cout<<endl;
                break;

            case 4:
                bt.inorder_r();
                cout<<endl;
                break;

            case 5:
                bt.preorder_r();
                cout<<endl;
                break;

            case 6:
                bt.postorder_r();
                cout<<endl;
                break;

            case 7:
                exit(0);
        }
    }
    return 0;
}