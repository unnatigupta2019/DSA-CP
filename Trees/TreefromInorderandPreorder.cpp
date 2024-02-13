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
Node *solve(int ps, int pe, int in[], int pre[], int is, int ie)
{
    if (is > ie)
    {
        return NULL;
    }
    int i;
    Node *root = new Node(pre[ps]);
    for (i = is; i < ie; i++)
    {
        if (root->data == in[i])
        {
            break;
        }
    }
    int ils = is;
    int ile = i - 1;
    int irs = i + 1;
    int ire = ie;

    int pls = ps + 1;
    int ple = pls + (ile - ils);
    int prs = ple + 1;
    int pree = pe;
    root->left = solve(pls, ple, in, pre, ils, ile);
    root->right = solve(prs, pree, in, pre, irs, ire);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{

    Node *root = solve(0, n - 1, in, pre, 0, n - 1);

    return root;
}
void Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
// also can be solved like this --
//  int pr = 0;
//      Node* solve(int in[],int pre[],int is ,int ie ){
//          if(is>ie){
//              return NULL;
//          }
//          int i;
//          Node* root = new Node(pre[pr++]);
//          for(i=is;i<ie;i++){
//              if(root->data == in[i]){
//                  break;
//              }
//          }
//          int ils = is;
//          int ile = i-1;
//          int irs = i+1;
//          int ire = ie;

//         root->left = solve(in,pre,ils,ile);
//         root->right =  solve(in,pre,irs,ire);
//         return root;
//     }
//     Node* buildTree(int in[],int pre[], int n)
//     {

//         Node* root = solve(in,pre,0,n-1);

//         return root;

//     }
int main()
{
    int inorder[] = {1, 6, 8, 7};
    int preorder[] = {1, 6, 7, 8};

    Node *n = buildTree(inorder, preorder, 4);
    Postorder(n);

    return 0;
}