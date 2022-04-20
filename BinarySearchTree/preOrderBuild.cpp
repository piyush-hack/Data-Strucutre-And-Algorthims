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

Node *conBST(int preOrder[] , int *preOrderIdx , int key , int min , int max , int n){

    if(*preOrderIdx > n){
        return NULL;
    }

    Node *root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preOrderIdx = *preOrderIdx + 1;

        if(*preOrderIdx < n){
            root->left = conBST(preOrder , preOrderIdx , preOrder[*preOrderIdx] , min , key , n);
        }

        if(*preOrderIdx < n ){
            root->right = conBST(preOrder , preOrderIdx , preOrder[*preOrderIdx] , key , max , n);
        }
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(struct Node *root)
{
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

    int preOrderS[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preOrderIdx = 0;
    Node *root = conBST(preOrderS , &preOrderIdx , preOrderS[0] , INT_MIN , INT_MAX , n);
    preOrder(root);

    return 0;
}