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
int solve(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int l = solve(node->left);
    int r = solve(node->right);
    return 1 + max(l, r);
}
// Function to find the height of a binary tree.
int height(struct Node *node)
{
    // code here
    if (node == NULL)
    {
        return 0;
    }
    if (node->left == NULL and node->right == NULL)
    {
        return 1;
    }
    return solve(node);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    cout << height(root);

    return 0;
}