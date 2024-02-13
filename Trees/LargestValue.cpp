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
vector<int> maximumValue(Node *node)
{
    // code here
    vector<int> ans;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int s = q.size();
        int a = INT_MIN;
        while (s--)
        {
            Node *n = q.front();
            q.pop();
            a = max(a, n->data);
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
        ans.push_back(a);
    }

    return ans;
}
int main()
{
    // Your code here
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->left->left = new Node(4);
    vector<int> a = maximumValue(root);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}