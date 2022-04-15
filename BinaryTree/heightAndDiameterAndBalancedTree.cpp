#include <bits/stdc++.h>

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


int treeHeight(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int lheight = treeHeight(root->left);
    int rheight = treeHeight(root->right);
    return max(lheight, rheight) + 1;
}

int treeDiameter(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int lheight = treeHeight(root->left);
    int rheight = treeHeight(root->right);
    int curDiameter = lheight + rheight + 1;
    int lDia = treeDiameter(root->left);
    int rDia = treeDiameter(root->right);

    // return curDiameter ;
    return max(curDiameter, max(lDia, rDia));
}

bool isBalanced(Node *root)
{

    if (root == NULL)
    {
        return true;
    }

    if (isBalanced(root->left) == false)
    {
        return false;
    }

    if (isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->left->left->left = new Node(8);
    // root->left->right->right = new Node(9);
    // root->left->left->left->left = new Node(10);
    // root->left->right->right->right = new Node(11);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << treeHeight(root) << endl;
    cout << treeDiameter(root) << endl;
    cout << isBalanced(root) << endl;

    return 0;
}