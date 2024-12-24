#include <vector>
#include <algorithm>
using namespace std;

void getInorder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    getInorder(root->left, v);
    v.push_back(root->data);
    getInorder(root->right, v);
}

void setInorder(vector<int> &v, Node *root, int &i)
{
    if (!root)
        return;
    setInorder(v, root->left, i);
    root->data = v[i++];
    setInorder(v, root->right, i);
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> v;
    getInorder(root, v);
    sort(v.begin(), v.end());
    int i = 0;
    setInorder(v, root, i);
    return root;
}
