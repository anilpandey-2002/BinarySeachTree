#include <bits/stdc++.h>
using namespace std;

// Node structure for a Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Insert a new node into the BST
Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Function to count nodes using Morris Traversal
int countNodes(Node *root)
{
    Node *current = root;
    int count = 0;

    while (current)
    {
        if (!current->left)
        {
            count++;
            current = current->right;
        }
        else
        {
            Node *pre = current->left;
            while (pre->right && pre->right != current)
                pre = pre->right;

            if (!pre->right)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = nullptr;
                count++;
                current = current->right;
            }
        }
    }
    return count;
}

// Function to find the median using Morris Traversal
int findMedian(Node *root)
{
    if (!root)
        return 0;

    int count = countNodes(root);
    int currCount = 0;
    Node *current = root;
    Node *prev = nullptr;

    while (current)
    {
        if (!current->left)
        {
            currCount++;

            // Check if current node is the median
            if (count % 2 != 0 && currCount == (count + 1) / 2)
                return current->data;
            if (count % 2 == 0 && currCount == (count / 2) + 1)
                return (prev->data + current->data) / 2;

            prev = current;
            current = current->right;
        }
        else
        {
            Node *pre = current->left;
            while (pre->right && pre->right != current)
                pre = pre->right;

            if (!pre->right)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = nullptr;

                prev = pre;
                currCount++;

                if (count % 2 != 0 && currCount == (count + 1) / 2)
                    return current->data;
                if (count % 2 == 0 && currCount == (count / 2) + 1)
                    return (prev->data + current->data) / 2;

                prev = current;
                current = current->right;
            }
        }
    }
    return 0;
}

// Driver program
int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Median of BST is " << findMedian(root) << endl;
    return 0;
}
