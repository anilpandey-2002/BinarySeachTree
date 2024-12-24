TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return NULL;
    if (root->val == key)
    {
        if (!root->right)
        {
            TreeNode *left = root->left;
            delete root;
            return left;
        }
        else if (!root->left)
        {
            TreeNode *right = root->right;
            delete root;
            return right;
        }
        else
        {
            TreeNode *right = root->right;
            while (right->left)
                right = right->left;
            swap(root->val, right->val);
        }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}
