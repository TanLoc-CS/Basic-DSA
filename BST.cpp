#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* pleft;
        Node* pright;
};

Node* CreateNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}
void addToNode(int x, Node* key)
{
    if (x < key->data){
        if (key->pleft == NULL)
            key->pleft = CreateNode(x);
        else 
            addToNode(x,key->pleft);
    }
    else{
        if (key->pright == NULL)
            key->pright = CreateNode(x);
        else 
            addToNode(x, key->pright);
    }
}

class BST{
    public:
        Node* root = NULL;
};

void addToBST(int x, BST &tree)
{
    if (!tree.root)
        tree.root = CreateNode(x);
    else
        addToNode(x, tree.root);
}
int getHeight(Node* p)
{
    int hL = 0, hR = 0;
    if (p->pleft != NULL)
        hL = getHeight(p->pleft);
    if (p->pright != NULL)
        hR = getHeight(p->pright);
    return 1 + max(hL, hR);
}
int main()
{
    int n;
    cin >> n;
    BST tree;
    for(int i = 0; i < n; i ++){
        int temp;
        cin >> temp;
        addToBST(temp, tree);
    }
    cout << getHeight(tree.root);
    return 0;
}