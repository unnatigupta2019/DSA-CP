#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
bool solve(Node *r1, Node *r2)
{
    if (r1 == NULL and r2 == NULL)
    {
        return true;
    }
    else if (r1 == NULL and r2 != NULL)
    {
        return false;
    }
    else if (r2 == NULL and r1 != NULL)
    {
        return false;
    }

    bool l = solve(r1->left, r2->left);
    bool r = solve(r1->right, r2->right);
    return r1->data == r2->data && l && r;
}
// Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2)
{
    // Your Code here
    if (r1 == NULL and r2 == NULL)
    {
        return true;
    }
    return solve(r1, r2);
}
int main()
{
    // Your code here
    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    root1->left->left->left = new Node(8);

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    // root2->left->left->left = new Node(8);

    cout << isIdentical(root1, root2);
    return 0;
}