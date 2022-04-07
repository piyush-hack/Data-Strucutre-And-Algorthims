#include <iostream>
// #include <stack>
using namespace std;
class que
{
    int st, en, *a, n;

public:
    que()
    {
        st = -1;
        en = -1;
        cout << "enter the size of the array " << endl;
        cin >> n;
        a = new int[n];
    }

    void push()
    {
        int ps;
        if (en == n - 1)
        {
            cout << "queue overflowed " << endl;
        }
        else
        {
            cout << "enter the elements of want to put " << endl;
            cin >> ps;
            en++;
            a[en] = ps;
            cout << "element has added!!" << endl;
        }

        if (st == -1)
        {
            st++;
        }
    }

    void pop()
    {
        if (st == -1 || st > en)
        {
            cout << "no elements " << endl;
        }
        else
        {
            st++;
            cout << "you have deleted one element successfully" << endl;
        }
    }

    void show()
    {
        if (st == -1 || st > en)
        {
            cout << "queue is empty " << endl;
        }
        else
        {
            cout << "the current que elements are " << endl;
            for (int i = st; i <= en; i++)
            {

                cout << a[i] << "\t";
            }
        }
    }
};

int main()
{
    que a;
    int c;
    while (1)
    {
        cout << "\n1->INSERT"
             << "\n"
             << "2->DELETE"
             << "\n"
             << "3->SHOW"
             << "\n"
             << "4->EXIT";
        cout << "\nenter your choice " << endl;
        cin >> c;
        if (c == 1)
        {
            a.push();
        }
        else if (c == 2)
        {
            a.pop();
        }
        else if (c == 3)
        {
            a.show();
        }
        else if (c == 4)
        {
            exit(0);
        }
        else
        {
            cout << "invalid keyword try again " << endl;
        }
    }

    cout << "program ended" << endl;

    return 0;
}