
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return (node);
}

struct Info
{
    int sz;
    int max;
    int min;
    int ans;

    bool isBST;
};

Info largestBSTBT(Node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    Info ret;
    ret.sz = (1 + l.sz + r.sz);

    if (l.isBST && r.isBST && l.max < root->data &&
        r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));

        ret.ans = ret.sz;
        ret.isBST = true;

        return ret;
    }

    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;

    return ret;
}

int main()
{

    struct Node *root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    printf(" Size of the largest BST is %d\n",
           largestBSTBT(root).ans);
    return 0;
}
