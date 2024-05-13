#include <iostream>
using namespace std;

class gnode
{
    string user;
    int vertex;
    gnode *next;
    friend class graph;
};

class graph
{
    int visited[20];
    gnode *head[20];
    int n;

public:
    graph()
    {
        cout << "ENtr the number of vertices ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            head[i] = new gnode;
            head[i]->vertex = i;
            cout << "Enter USername: ";
            cin >> head[i]->user;
            head[i]->next = NULL;
        }
    }

    void create();
    void dfs();
    void dfs(int v);
    void dfs_nr(int v);
    void display();
};

class que
{
    int front, rear;
    int q[20];

public:
    que()
    {
        front = rear = -1;
    }
    void enq(int n);
    int deq();
    int full()
    {
        if (rear == 19)
        {
            return 1;
        }
        return 0;
    }
    int empty()
    {
        if (front = rear || (front == -1 && rear == -1))
        {
            return 1;
        }
        return 0;
    }
    friend class graph;
};

void que ::enq(int n)
{
    if (full())
    {
        cout << "Que is full";
    }
    rear++;
    q[rear] = n;
}

int que::deq()
{
    if (empty())
    {
        cout << "Que khali aahe ";
        return -1;
    }
    front++;
    int temp = q[front];
    return temp;
}
class stackk
{
    int top;
    int data[20];

public:
    stackk()
    {
        top = -1;
    }
    void push(int temp);
    int pop();
    int empty();
};
void stackk::push(int temp)
{
    if (top < 20)
    {
        top++;
        data[top] = temp;
    }
    else
    {
        cout << "Stack overflow" << endl;
    }
}

int stackk::pop()
{
    if (!empty())
    {
        int temp = data[top];
        top--;
        return temp;
    }
    else
    {
        cout << "Stack Underflow" << endl;
    }
}

int stackk::empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void graph::create()
{
    char ch;
    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i];
        cout << "\nAdjacency list of " << head[i]->user << "" << endl;
        do
        {
            int v;
            cout << "Enter adjacent vertex of " << head[i]->user << ":" << endl;
            cin >> v;

            if (v == i)
            {
                cout << "Self loop not allowed";
            }
            else
            {
                gnode *curr = new gnode;
                curr->next = NULL;
                curr->vertex = v;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = curr;
            }
            cout << "More nodes? ";
            cin >> ch;
        } while (ch == 'y');
    }
}

void graph::display()
{
    gnode *temp;
    for (int i = 0; i < n; i++)
    {
        temp = head[i]->next;
        cout << "Adjacency list for " << head[i]->user << " " << endl;
        while (temp != NULL)
        {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << "ENd" << endl;
    }
}
void graph::dfs_nr(int v)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    stackk st;
    st.push(v);
    do
    {
        v = st.pop();
        cout << head[v]->user << " ";
        visited[v] = 1;

        gnode *temp = head[v]->next;
        while (temp != NULL)
        {
            int w = temp->vertex;
            if (!visited[w])
            {
                st.push(w);
                visited[w] = 1;
            }
            temp = temp->next;
        }
    } while (!st.empty());
}
int main()
{
    graph g;

    g.create();
    g.display();
    int num;
    cout << "Enter the value of the vertex u want to start traversing with ";
    cin >> num;
    g.dfs_nr(num);
    return 0;
}