#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
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
void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
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
void Levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        int s = q.size();

        while (s--)
        {
            Node *l = q.front();
            q.pop();
            cout << l->data << " ";
            if (l->left != NULL)
            {

                q.push(l->left);
            }
            if (l->right != NULL)
            {

                q.push(l->right);
            }
        }
        cout << endl;
    }
}
// using two stacks
//  vector<int> findSpiral(Node *root)
//    {  vector<int>v;
//      stack<Node*>s1;
//      stack<Node*>s2;
//    if(root==NULL){
//      return v;
//  }
//      s1.push(root);
//      while(!s1.empty()|| !s2.empty()){
//          while(!s1.empty()){
//              Node*t = s1.top();
//              v.push_back(t->data);
//              s1.pop();
//              if(t->right){
//                  s2.push(t->right);
//              }
//              if(t->left){
//                  s2.push(t->left);
//              }
//          }
//          while(!s2.empty()){
//              Node*t = s2.top();
//              v.push_back(t->data);
//              s2.pop();
//              if(t->left){
//                  s1.push(t->left);
//              }
//              if(t->right){
//                  s1.push(t->right);
//              }
//          }

//     }
//     return v;

// }
void Levelorderspiral(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    int r = 0;

    vector<int> ans;
    while (!q.empty())
    {

        int s = q.size();
        vector<int> a;
        while (s--)
        {
            Node *l = q.front();
            q.pop();
            a.push_back(l->data);
            if (l->left != NULL)
            {

                q.push(l->left);
            }
            if (l->right != NULL)
            {

                q.push(l->right);
            }
        }
        r = 1 - r;
        if (r == 0)
        {
            reverse(a.begin(), a.end());
        }
        for (auto x : a)
        {
            ans.push_back(x);
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
}

void leftBoundary(Node *root)
{

    if (root != NULL and root->left == NULL and root->right == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        leftBoundary(root->left);
    }
    else
    {
        leftBoundary(root->right);
    }
    return;
}
void leaves(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    leaves(root->left);
    if (root != NULL and root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leaves(root->right);
}
void rightBoundary(Node *root)
{

    if (root != NULL and root->left == NULL and root->right == NULL)
    {
        return;
    }

    if (root->right != NULL)
    {

        rightBoundary(root->right);
    }
    else
    {
        rightBoundary(root->left);
    }
    ans.push_back(root->data);
}
vector<int> Boundaryorder(Node *root)
{
    if (root == NULL)
    {
        return ans;
    }
    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
        return ans;
    }
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        leftBoundary(root->left);
    }
    leaves(root);
    if (root->right != NULL)
    {
        rightBoundary(root->right);
    }
    return ans;
}
vector<int> Diagonalorder(Node *root)
{
    vector<int> ans1;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        int s = q.size();
        while (s--)
        {
            Node *f = q.front();
            q.pop();
            while (f)
            {
                ans1.push_back(f->data);
                if (f->left)
                {
                    q.push(f->left);
                }
                f = f->right;
            }
        }
    }

    return ans1;
}
void verticalTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<Node *, int>> q;
    map<int, vector<int>> m;
    q.push({root, 0});
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            Node *f = q.front().first;
            int l = q.front().second;
            m[l].push_back(f->data);
            q.pop();

            if (f->left)
            {
                q.push({f->left, l - 1});
            }
            if (f->right)
            {
                q.push({f->right, l + 1});
            }
        }
    }
    for (auto x : m)
    {
        cout << x.first << "-->";
        for (auto y : x.second)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // cout << endl;
    // Inorder(root);
    // cout << endl;
    // Preorder(root);
    // cout << endl;
    // Postorder(root);
    // cout << endl;
    // Levelorder(root);
    // cout << endl;
    // Levelorderspiral(root);
    // cout << endl;
    // vector<int> v = Boundaryorder(root);
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // vector<int> u = Diagonalorder(root);
    // for (auto x : u)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    verticalTraversal(root);
    return 0;
}