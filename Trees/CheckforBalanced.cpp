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
int h(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    int l = h(n->left);
    int r = h(n->right);
    return 1 + max(l, r);
}
bool solve(Node *root)
{

    if (root == NULL)
    {
        return true;
    }
    bool l = solve(root->left);
    bool r = solve(root->right);
    int l1 = h(root->left);
    int r1 = h(root->right);

    return abs(l1 - r1) <= 1 && l && r;
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return true;
    }

    return solve(root);
}

// In two loops ---
//  int solve(Node* root){

//       if(root==NULL){
//           return 0;
//       }

//       int   l  = solve(root->left);
//        if(l==-1){
//            return -1;
//        }
//       int r = solve(root->right);
//       if(r==-1){
//           return -1;
//       }

//       if(abs(l-r)>1 ){
//           return -1;
//       }
//     return  1 + max(l,r);
//     }
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(3);
    cout << isBalanced(root);
    return 0;
}