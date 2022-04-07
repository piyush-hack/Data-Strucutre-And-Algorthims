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

int search(int inOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
        {
            return i;
        }
    }

    return -1;
}

Node *buildTree(int postOrder[], int inOrder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }

    int curr = postOrder[idx];
    idx--;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }
    
    int pos = search(inOrder, start, end, curr);
    node->right = buildTree(postOrder, inOrder, pos + 1, end);
    node->left = buildTree(postOrder, inOrder, start, pos - 1);

    return node;
}

void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{

    int postOrder[] = {4, 2, 5, 3, 1};
    int inOrder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(postOrder, inOrder, 0, 4);
    inorderPrint(root);
    return 0;
}