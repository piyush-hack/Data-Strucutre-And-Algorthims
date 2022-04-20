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

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
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

Node *searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

Node *inOrderSucc(Node *root){
    Node  *curr = root;
    while(curr && curr->left !=NULL){
        curr = curr->left;
    }
    return curr;
}
Node *deleteBST(Node *root, int key)
{
    if(key < root->data){
        root->left = deleteBST(root->left , key);
    }else if(root->data < key){
        root->right = deleteBST(root->right , key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right , temp->data);
    }
    return root;
}

int main()
{

    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    // BSt inorder is always sorted
    string ans = searchBST(root, 1) ? "Exists" : "Not Exists";
    cout << ans << endl;

    inorder(root);
    root = deleteBST(root, 2);
    cout << endl;
    inorder(root);
    return 0;
}