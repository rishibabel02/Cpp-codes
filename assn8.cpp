#include <bits/stdc++.h>
using namespace std;

class heap
{
    int student[20];
    int n;

public:
    void add(int x);
    void display();
    void heapup(int n);
    void heapsort();
    void adjust(int n, int i);
};

void heap::add(int x)
{
    int j = 0;
    char ch;
    do
    {
        int el;
        cout << "Enter the marks of student " << j + 1 << endl;
        cin >> el;
        student[j] = el;
        heapup(j + 1);
        j++;

        // cout << "Want to add more? (y/n)" << endl;
        // cin >> ch;

    } while (j < x);
    n = j;
}

void heap::heapup(int n)
{
    int i = n;
    int el = student[n - 1];
    if (i != 1)
    {
        while ((i > 0) && (student[(i / 2) - 1] < el))
        {
            student[i - 1] = student[(i / 2) - 1];
            i = (i / 2);
        }
        student[i - 1] = el;
    }
}

void heap::display()
{
    cout << "The marks are as follows:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << student[i] << " ";
    }
    cout << endl;
}

void heap::heapsort()
{
    int temp = n;
    while (temp > 0)
    {
        int t = student[0];
        student[0] = student[temp - 1];
        student[temp - 1] = t;
        temp--;
        adjust(temp - 1, 0);
    }
}

void heap::adjust(int n, int i)
{
    while (2 * i + 1 <= n)
    {
        int j = (2 * i) + 1;
        if ((j + 1 <= n) and (student[j + 1] > student[j]))
        {
            j = j + 1;
        }
        if (student[i] >= student[j])
            break;
        else
        {
            int temp = student[i];
            student[i] = student[j];
            student[j] = temp;
            i = j;
        }
    }
}

int main()
{
    int x;
    cout << "Enter no. of students: ";
    cin >> x;
    heap marks;
    marks.add(x);
    marks.display();
    marks.heapsort();
    cout << "Sorted-->" << endl;
    marks.display();

    return 0;
}
