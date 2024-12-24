#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;
    if (root->key == key)
    {
        if (root->left)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }
        if (root->right)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }
    if (root->key > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key)
{
    if (!node)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int main()
{
    int key = 65;
    Node *root = NULL, *pre = NULL, *suc = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    findPreSuc(root, pre, suc, key);
    cout << (pre ? "Predecessor is " + to_string(pre->key) : "No Predecessor") << endl;
    cout << (suc ? "Successor is " + to_string(suc->key) : "No Successor") << endl;
    return 0;
}

void find_p_s(Node *root, int a, Node **p, Node **q)
{
    if (!root)
        return;
    find_p_s(root->left, a, p, q);
    if (root->data > a && (!*q || (*q)->data > root->data))
        *q = root;
    else if (root->data < a)
        *p = root;
    find_p_s(root->right, a, p, q);
}
