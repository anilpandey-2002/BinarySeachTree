
void getKthLargest(Node *root, priority_queue<int, vector<int>, greater<int>> &pq, int sz)
{
    if (!root)
        return;

    getKthLargest(root->left, pq, sz);
    pq.push(root->data);
    if (pq.size() > sz)
        pq.pop();
    getKthLargest(root->right, pq, sz);
}

int kthLargest(Node *root, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    getKthLargest(root, pq, K);

    return pq.top();
}
