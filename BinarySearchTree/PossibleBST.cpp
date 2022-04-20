#include <iostream>
#include <vector>

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

vector<Node *> consTree(int start, int end)
{
    vector<Node *> tress;

    if (start > end)
    {
        tress.push_back(NULL);
        return tress;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtress = consTree(start, i - 1);
        vector<Node *> rightSubtress = consTree(i + 1, end);

        for (int j = 0; j < leftSubtress.size(); j++)
        {
            Node *left = leftSubtress[j];
            for (int k = 0; k < rightSubtress.size(); k++)
            {
                Node *right = rightSubtress[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                tress.push_back(node);
            }
        }
    }

    return tress;
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

    vector<Node *> ttress = consTree(1, 3);
    for (int i = 0; i < ttress.size(); i++)
    {
        cout << (i + 1) << " : ";
        preOrder(ttress[i]);
        cout << endl;
    }
    return 0;
}