#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void storeInorder(Node *root, vector<int> &inorder)
{
    if (!root)
        return;
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

vector<int> merge(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> mergedArr(arr1.size() + arr2.size());
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), mergedArr.begin());
    return mergedArr;
}

Node *sortedArrayToBST(const vector<int> &arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

Node *mergeTrees(Node *root1, Node *root2)
{
    vector<int> inorder1, inorder2;
    storeInorder(root1, inorder1);
    storeInorder(root2, inorder2);

    vector<int> mergedInorder = merge(inorder1, inorder2);
    return sortedArrayToBST(mergedInorder, 0, mergedInorder.size() - 1);
}

void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node *mergedTree = mergeTrees(root1, root2);
    cout << "Inorder traversal of the merged tree:\n";
    printInorder(mergedTree);

    return 0;
}
