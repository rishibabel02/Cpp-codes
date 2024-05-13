#include <iostream>
using namespace std;

class treenode
{
    int data;
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree();
    void create_nr();
    void inorder_r()
    {
        inorder_r(root);
    }//driver function 
    void inorder_r(treenode *temp); //actual member function which is used to traverse (workshorse)

    void preorder_r()
    {
        preorder_r(root);
    }
    void preorder_r(treenode *temp);

    void postorder_r()
    {
        postorder_r(root);
    }
    void postorder_r(treenode *temp);
};

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

tree::tree()
{
    root = NULL;
}

void tree::inorder_r(treenode *temp)
{

    if (temp != NULL)
    {
        inorder_r(temp->left);
        cout << temp->data << " ";
        inorder_r(temp->right);
    }
}

void tree::preorder_r(treenode *temp)
{

    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}
void tree::postorder_r(treenode *temp)
{

    if (temp != NULL)
    {
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout << temp->data << " ";
    }
}
int main()
{
    tree bt;
    bt.create_nr();

    cout << "Which Traversing Method Would You Like to Choose?" << endl;
    int n;
    cin >> n;
    
    switch (n)
    {
    case 1:
        cout << "1.Inorder Traversal:\n";
        bt.inorder_r();
        break;

    case 2:
        cout << "\n 2.Preorder Traversal:\n";
        bt.preorder_r();
        break;

    case 3:
        cout << "\n 3.Postorder Traversal:\n";
        bt.postorder_r();
        break;
    }
    return 0;
}
