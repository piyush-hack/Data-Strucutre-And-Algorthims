#include <iostream>

using namespace std;
class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
        }
        else
        {
            back->next = n;
            back = n;
        }
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        node *del = front;
        front = front->next;
        delete del;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "No Element" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;

    return 0;
}