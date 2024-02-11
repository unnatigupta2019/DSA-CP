// Mirror image of itself
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
bool solve(Node *p, Node *q)
{
    if (p == NULL and q == NULL)
    {
        return true;
    }
    if ((p == NULL and q != NULL) or (q == NULL and p != NULL))
    {
        return false;
    }
    return p->data == q->data && solve(p->left, q->right) && solve(p->right, q->left);
}
bool isSymmetric(struct Node *root)
{
    if (root == NULL or (root->left == NULL and root->right == NULL))
    {
        return true;
    }
    return solve(root->left, root->right);
}
// using stack --
// if (root == NULL)
// {
//     return true;
// }

// // Create a stack to store the left and right subtrees
// // of the root.
// stack<Node *> stack;
// stack.push(root->left);
// stack.push(root->right);

// // Continue the loop until the stack is empty.
// while (!stack.empty())
// {
//     // Pop the left and right subtrees from the stack.
//     Node *node1 = stack.top();
//     stack.pop();
//     Node *node2 = stack.top();
//     stack.pop();

//     // If both nodes are null, continue the loop.
//     if (node1 == NULL && node2 == NULL)
//     {
//         continue;
//     }

//     // If one of the nodes is null, the binary tree is
//     // not symmetric.
//     if (node1 == NULL || node2 == NULL)
//     {
//         return false;
//     }

//     // If the values of the nodes are not equal, the
//     // binary tree is not symmetric.
//     if (node1->key != node2->key)
//     {
//         return false;
//     }

//     // Push the left and right subtrees of the left and
//     // right nodes onto the stack in the opposite order.
//     stack.push(node1->left);
//     stack.push(node2->right);
//     stack.push(node1->right);
//     stack.push(node2->left);
int main()
{
    // Your code here
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    // root->right->right = new Node(3);
    cout << isSymmetric(root);
    return 0;
}