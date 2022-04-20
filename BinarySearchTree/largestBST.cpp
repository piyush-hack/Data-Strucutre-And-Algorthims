#include <iostream>
#include <climits>

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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root){
    if(root == NULL){
        return {0, INT_MIN , INT_MAX , 0 , true};
    }

    if(root->left == NULL && root->right == NULL){
        return {1, root->data , root->data , 1 , true};
    }

    Info lIn = largestBST(root->left);
    Info rIn = largestBST(root->right);

    Info curr;
    curr.size = (1+ lIn.size + rIn.size);

    if(lIn.isBST && rIn.isBST && lIn.max < root->data && rIn.min > root->data){
        curr.min = min(lIn.min , min(rIn.min , root->data));
        curr.min = max(rIn.max , max(lIn.max , root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    curr.ans = max(lIn.ans , rIn.ans);
    curr.isBST = false;
    return curr;
}



int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(-1);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int a = largestBST(root).ans;

    cout << a << endl;

    return 0;
}