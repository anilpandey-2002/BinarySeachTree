
void getKthSmallest(Node *root, priority_queue<int> &pq, int sz)
{
    if (!root)
        return;

    getKthSmallest(root->left, pq, sz);
    pq.push(root->data);
    if (pq.size() > sz)
        pq.pop();
    getKthSmallest(root->right, pq, sz);
}

int KthSmallestElement(Node *root, int K)
{
    priority_queue<int> pq;
    getKthSmallest(root, pq, K);

    return (pq.size() == K) ? pq.top() : -1;
}
