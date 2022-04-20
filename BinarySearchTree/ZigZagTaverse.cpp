#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTraversal(Node *root)
{
    if(root == NULL){
        return;
    }

    stack<Node *> curr;
    stack<Node *> next;

    bool ltr = true;

    curr.push(root);
    while (!curr.empty())
    {
        Node *temp = curr.top();
        curr.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (ltr)
            {
                if (temp->left)
                {
                    next.push(temp->left);
                }
                if (temp->right)
                {
                    next.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    next.push(temp->right);
                }
                if (temp->left)
                {
                    next.push(temp->left);
                }
            }

            if(curr.empty()){
                ltr = !ltr;
                swap(curr , next);
            }
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    zigzagTraversal(root);

    return 0;
}