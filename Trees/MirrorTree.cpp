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
void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void solve(Node *n)
{
    // cout<<n->data<<" ";
    if (n == NULL)
    {
        return;
    }
    Node *temp = n->right;
    n->right = n->left;
    n->left = temp;
    solve(n->left);
    solve(n->right);
    return;
}
void mirror(Node *node)
{
    // code here
    if (node == NULL or (node->right == NULL and node->left == NULL))
    {
        return;
    }

    solve(node);
}
// can also do like this --
//  if (node == NULL)
//          return;
//      else {
//          struct Node* temp;

//         /* do the subtrees */
//         mirror(node->left);
//         mirror(node->right);

//         /* swap the pointers in this node */
//         temp = node->left;
//         node->left = node->right;
//         node->right = temp;
//     }

// using level order--
//  if (root == NULL)
//          return;

//     queue<Node*> q;
//     q.push(root);

//     // Do BFS. While doing BFS, keep swapping
//     // left and right children
//     while (!q.empty()) {
//         // pop top node from queue
//         Node* curr = q.front();
//         q.pop();

//         // swap left child with right child
//         swap(curr->left, curr->right);

//         // push left and right children
//         if (curr->left)
//             q.push(curr->left);
//         if (curr->right)
//             q.push(curr->right);
//     }
int main()
{
    // Your code here
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    mirror(root);
    Inorder(root);
    return 0;
}