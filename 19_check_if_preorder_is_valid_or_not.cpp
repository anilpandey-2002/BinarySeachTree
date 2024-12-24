
void constructBST(Node **root, int key)
{
    if (!(*root))
        return;

    if ((*root)->data > key)
    {
        if ((*root)->left == NULL)
            (*root)->left = newNode(key);
        else
            constructBST(&(*root)->left, key);
    }
    else
    {
        if ((*root)->right == NULL)
            (*root)->right = newNode(key);
        else
            constructBST(&(*root)->right, key);
    }
}

Node *constructTree(int pre[], int size)
{
    Node *root = newNode(pre[0]);

    for (int i = 1; i < size; i++)
    {
        constructBST(&root, pre[i]);
    }
    return root;
}
