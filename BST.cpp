#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *pLeft;
    Node *pRight;
};

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void addToNode(int x, Node *key)
{
    if (x < key->data)
    {
        if (key->pLeft == NULL)
            key->pLeft = CreateNode(x);
        else
            addToNode(x, key->pLeft);
    }
    else
    {
        if (key->pRight == NULL)
            key->pRight = CreateNode(x);
        else
            addToNode(x, key->pRight);
    }
}

class BST
{
public:
    Node *root = NULL;
};

void addToBST(int x, BST &tree)
{
    if (!tree.root)
        tree.root = CreateNode(x);
    else
        addToNode(x, tree.root);
}
int getHeight(Node *p)
{
    int hL = 0, hR = 0;
    if (p->pLeft != NULL)
        hL = getHeight(p->pLeft);
    if (p->pRight != NULL)
        hR = getHeight(p->pRight);
    return 1 + max(hL, hR);
}
int main()
{
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        addToBST(temp, tree);
    }
    cout << getHeight(tree.root);
    return 0;
}