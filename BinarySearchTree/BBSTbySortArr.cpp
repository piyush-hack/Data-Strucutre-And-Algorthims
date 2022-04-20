#include <iostream>

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

Node *srtArrToBST(int arr[], int start, int end)
{
    cout<< " here" << endl;

    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = srtArrToBST(arr, start, mid - 1);
    root->right = srtArrToBST(arr, mid + 1, end);

    return root;
}

void preOrder(Node *root)
{
    // cout << root->data << " here" << endl;
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    Node *root = srtArrToBST(arr, 0, 4);

    preOrder(root);

    return 0;
}