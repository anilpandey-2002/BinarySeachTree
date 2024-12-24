
void util(Node *root, int l, int h, int &cnt)
{
    if (!root)
        return;

    if (root->data >= l && root->data <= h)
        cnt++;

    util(root->left, l, h, cnt);
    util(root->right, l, h, cnt);
}

int getCount(Node *root, int l, int h)
{
    int cnt = 0;
    util(root, l, h, cnt);
    return cnt;
}
