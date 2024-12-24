#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key)
{
    if (!node)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void storeNodes(Node *root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes)
{
    if (!root)
        return;
    all_nodes.insert(root->data);
    if (!root->left && !root->right)
        leaf_nodes.insert(root->data);
    storeNodes(root->left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

bool isDeadEnd(Node *root)
{
    if (!root)
        return false;
    unordered_set<int> all_nodes = {0}, leaf_nodes;
    storeNodes(root, all_nodes, leaf_nodes);
    for (int x : leaf_nodes)
        if (all_nodes.count(x + 1) && all_nodes.count(x - 1))
            return true;
    return false;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    cout << (isDeadEnd(root) ? "Yes" : "No") << endl;
    return 0;
}
