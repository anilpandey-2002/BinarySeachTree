#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void storeBSTNodes(Node *root, vector<Node *> &nodes)
{
    if (!root)
        return;
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

Node *buildTreeUtil(vector<Node *> &nodes, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = nodes[mid];
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);
    return root;
}

Node *buildTree(Node *root)
{
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
    return buildTreeUtil(nodes, 0, nodes.size() - 1);
}

Node *newNode(int data)
{
    return new Node{data, NULL, NULL};
}

void preOrder(Node *node)
{
    if (!node)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);

    root = buildTree(root);
    printf("Preorder traversal of balanced BST is:\n");
    preOrder(root);

    return 0;
}
