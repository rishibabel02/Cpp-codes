#include <iostream>
using namespace std;

class tbtnode
{
    int data;
    bool rbit;
    bool lbit;
    tbtnode *rightc;
    tbtnode *leftc;
    friend class tbt;

public:
    tbtnode();
};

tbtnode::tbtnode()
{
    lbit = 0;
    rbit = 0;
}

class tbt
{
    tbtnode *head;

public:
    void create();
    void inorder();
    void preorder();
    tbtnode *insuccr(tbtnode *temp);
    tbt();
};

tbt::tbt()
{
    head = new tbtnode;
    head->rbit = 1;
    head->leftc = head;
    head->rightc = head;
}

void tbt::create()
{
    tbtnode *root = new tbtnode;
    cout << "Enter the data for root:" << endl;
    cin >> root->data;
    head->lbit = 1;
    root->leftc = head;
    root->rightc = head;
    head->leftc = root;

    char ch2;
    do
    {
        int flag = 0;
        tbtnode *temp = root;
        tbtnode *curr = new tbtnode;
        cout << "Enter the data for curr:" << endl;
        cin >> curr->data;
        char ch1;
        while (flag == 0)
        {
            cout << "Where do you want to insert the node (l/r)? of " << temp->data << endl;
            cin >> ch1;
            if (ch1 == 'l')
            {
                if (temp->lbit == 0)
                {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    flag = 1;
                }
                else
                {
                    temp = temp->leftc;
                }
            }
            else if (ch1 == 'r')
            {
                if (temp->rbit == 0)
                {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 1;
                    flag = 1;
                }
                else
                {
                    temp = temp->rightc;
                }
            }
        }
        cout << "Do you want to add more nodes (y/n)? " << endl;
        cin >> ch2;
    } while (ch2 == 'y');
}

void tbt::inorder()
{
    tbtnode *temp = head;
    while (1)
    {
        temp = insuccr(temp);
        if (temp == head)
        {
            break;
        }
        cout << temp->data << " "; 
    }
}

tbtnode *tbt::insuccr(tbtnode *temp)
{
    tbtnode *x = temp->rightc;
    if (temp->rbit == 1)
    {
        while (x->lbit == 1)
        {
            x = x->leftc;
        }
    }
    return x;
}
void tbt::preorder()
{
    tbtnode *temp = head->leftc;
    while (temp != head)
    {
        cout << temp->data << " ";
        while (temp->lbit != 0)
        {
            temp = temp->leftc;
            cout << temp->data << " ";
        }
        while (temp->rbit == 0)
        {
            temp = temp->rightc;
        }
        temp = temp->rightc;
    }
}
int main()
{
    tbt tree;
    tree.create();
    cout << "Inorder Traversal is: " << endl;
    tree.inorder();
    cout << "\nPreorder Traversal is: " << endl;
    tree.preorder();
    return 0;
}
