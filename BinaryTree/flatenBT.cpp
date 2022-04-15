#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *flatten(Node *root)
{

    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return root;
    }
    if (root->left != NULL)
    {
        flatten(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }

        t->right = temp;
    }

   
    flatten(root->right);
    return root;
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


    Node *flatRoot  = flatten(root);
     while (flatRoot->right != NULL)
    {
        cout << flatRoot->data << " ";
        flatRoot = flatRoot->right;
    }

    return 0;
}