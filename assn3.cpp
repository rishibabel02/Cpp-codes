#include <bits/stdc++.h>
using namespace std;
class treenode
{
    string data;
    string mean;
    treenode *left;
    treenode *right;
    friend class tree;
};

class queueee
{
    int front, rear;
    treenode *q[30];

public:
    queueee()
    {
        front = rear = -1;
    }
    void enqueueee(treenode *next);
    treenode *dequeueee();
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
        if (front == rear || (front == -1 && rear == -1))
        {
            return 1;
        }
        return 0;
    }
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree();

    void create_bst();
    void inorder_r()
    {
        inorder_r(root);
    }
    void inorder_r(treenode *temp);

    void BFS();
    void mirror_r()
    {
        mirror_r(root);
        BFS();
        // inorder_r();
    }
    void mirror_r(treenode *root);

    void mirror_nr()
    {
        mirror_nr(root);
        BFS();
    }
    void mirror_nr(treenode *root);

    void copy();
    treenode *copy(treenode *);

    void search();
    void search_nr();
    void deleteNode();
};

tree::tree()
{
    root = NULL;
}

void tree ::create_bst()
{
    root = new treenode;
    root->left = NULL;
    root->right = NULL;
    cout << "Enter the value of root node :" << endl;
    cin >> root->data;
    cout<<"Enter its meaning: "<<endl;
    cin>>root->mean;
    char dat;
    do
    {
        treenode *temp = root;
        int flag = 0;
        treenode *curr = new treenode;
        curr->left = NULL;
        curr->right = NULL;
        cout << "ENter the data for next node:" << endl;
        cin >> curr->data;
        cout<<"Enter its meaning: "<<endl;
    cin>>curr->mean;
        while (flag == 0)
        {
            if (curr->data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }

            else
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        cout << "Do you wan to add more nodes? (y/n)" << endl;
        cin >> dat;
    } while (dat == 'y');
}

void tree::inorder_r(treenode *temp)
{

    if (temp != NULL)
    {
        inorder_r(temp->left);
        cout << temp->data << "{"<<temp->mean<<"}";
        inorder_r(temp->right);
    }
}

void queueee::enqueueee(treenode *next)
{
    if (isfull())
    {
        cout << "The queuee is full!!" << endl;
    }
    rear++;
    q[rear] = next;
}
treenode *queueee ::dequeueee()
{
    if (isempty())
    {
        cout << "The queuee is empty!!" << endl;
        return NULL;
    }
    front++;
    treenode *temp = q[front];
    return temp;
}

void tree::BFS()
{
    int p = 1;
    int r = 0;
    queueee que;
    treenode *temp = root;
    que.enqueueee(temp);

    while (!que.isempty())
    {
        for (int i = 0; i < p; i++)
        {

            temp = que.dequeueee();
            cout << temp->data << "{"<<temp->mean<<"} ";
            if (temp->left != NULL)
            {
                que.enqueueee(temp->left);
                r++;
            }
            if (temp->right != NULL)
            {
                que.enqueueee(temp->right);
                r++;
            }
        }
        cout << endl;
        p = r;
        r = 0;
    }
}
void tree::mirror_r(treenode *root)
{
    treenode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left != NULL)
    {
        mirror_r(root->left);
    }
    if (root->right != NULL)
    {
        mirror_r(root->right);
    }
}
void tree::mirror_nr(treenode *root)
{
    queueee que;
    treenode *temp = root;
    que.enqueueee(temp);

    while (!que.isempty())
    {
        temp = que.dequeueee();

        if (temp->left != NULL)
        {
            que.enqueueee(temp->left);
        }
        if (temp->right != NULL)
        {
            que.enqueueee(temp->right);
        }
        treenode *tempswap = temp->left;
        temp->left = temp->right;
        temp->right = tempswap;
        // cout << temp->data << " ";
    }
}
void tree::copy()
{
    tree t2;
    t2.root = copy(root);
    t2.BFS();
}
treenode *tree ::copy(treenode *root)
{
    treenode *temp = NULL;
    if (root != NULL)
    {
        temp = new treenode;
        temp->data = root->data;
        temp->mean = root->mean;
        temp->left = copy(root->left);
        temp->right = copy(root->right);
    }
    return temp;
}

void tree::search_nr()
{
    int flag = 0;
    treenode *temp = root;
    string str;
    cout << "\nEnter the string to be searched:" << endl;
    cin >> str;
    while (temp != NULL)
    {
        if (str == temp->data)
        {
            flag = 1;
            break;
        }
        else if (str < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (flag == 1)
    {
        cout << "String Found" << endl;
    }
    else
    {
        cout << "String Not Found" << endl;
    }
}
void tree::deleteNode()
{
    int flag = 0;
    treenode *temp, *parent, *s, *curr;
    temp = root;
    parent = root;
    s = NULL;
    string del;
    cout << "\nEnter the string to be Deleted:" << endl;
    cin >> del;
    while (temp != NULL)
    {
        if (del == temp->data)
        {
            curr = temp;
            flag = 1;
            break;
        }
        else if (del < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else if (del > temp->data)
        {
            parent = temp;
            temp = temp->right;
        }
        else
        {
            cout << "Value Not FOund" << endl;
        }
    }
    if (curr == root)
    {
        if (curr->right == NULL)
        {
            root = root->left;
        }
        else if (curr->left == NULL)
        {
            root = root->right;
        }
        else if (curr->right != NULL && curr->left != NULL)
        {
            temp = curr->left;
            root = curr->right;
            s = curr->right;
            while (s->left != NULL)
            {
                s = s->left;
            }
            s->left = temp;
        }
    }
    else if (curr != root)
    {
        if (curr->left == NULL && curr->right == NULL)
        {
            if (parent->left == curr)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        else if (curr->left == NULL)
        {
            if (parent->left == curr)
                parent->left = curr->right;
            else
                parent->right = curr->left;
        }

        else if (curr->left == NULL)
        {
            if (parent->left == curr)
                parent->left = curr->right;
            else
                parent->right = curr->left;
        }
        else if (curr->right == NULL)
        {
            if (parent->left == curr)
                parent->left = curr->left;
            else
                parent->right = curr->right;
        }

        else
        {
            s = curr->right;
            temp = curr->left;
            while (s->left != NULL)
            {
                s = s->left;
            }
            s->left = temp;
            if (parent->left == curr)
                parent->left = curr->right;
            else
                parent->right = curr->right;
        }
    }
}

int main()
{
    tree bst;
    while (1)
    {
        cout << endl
             << "Which operation would you like to perform?" << endl
             << "1. Creation of a binary search tree" << endl
             << "2. Displaying using BFS" << endl
             << "3. Search an element" << endl
             << "4. Copying of BST" << endl
             << "5. Mirror Image of the tree" << endl
             << "6. Delete a node from the tree" << endl
             << "7. Exit" << endl;

        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            bst.create_bst();
            break;
        case 2:
            cout << "Level Wise display: " << endl;
            bst.BFS();
            cout << endl;
            break;
        case 3:
            bst.search_nr();
            break;

        case 4:
            bst.copy();
            break;
        case 5:
            cout << "Mirror image to the tree will be(Recursive):" << endl;
            bst.mirror_r();
            cout << "Mirror image to the tree will be(Non-Recursive):" << endl;
            bst.mirror_nr();

            cout << endl;
            break;
        case 6:
            bst.deleteNode();
            cout << "BST after deleting the data" << endl;
            bst.BFS();
            cout << endl;
            break;
        case 7:
            exit(0);
        }
    }

    return 0;
}