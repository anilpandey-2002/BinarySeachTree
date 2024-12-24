void insert(Node *root, int key)
{
    Node *node = new Node(key);
    if (root == null)
    {
        root = node;
        return;
    }

    Node prev = null;
    Node temp = root;
    while (temp != null)
    {
        if (temp.val > key)
        {
            prev = temp;
            temp = temp->left;
        }
        else if (temp.val < key)
        {
            prev = temp;
            temp = temp->right;
        }
    }

    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}