
void populateNext(node *p)
{

    static node *next = NULL;

    if (p)
    {

        populateNext(p->right);

        p->next = next;

        next = p;

        populateNext(p->left);
    }
}
