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
vector<int> rightView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        ans.push_back(q.front()->data);
        while (s--)
        {
            Node *n = q.front();
            q.pop();
            if (n->right)
            {
                q.push(n->right);
            }
            if (n->left)
            {
                q.push(n->left);
            }
        }
    }
    return ans;
}
vector<int> leftView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        ans.push_back(q.front()->data);
        while (s--)
        {
            Node *n = q.front();
            q.pop();
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
    }
    return ans;
}
vector<int> topView(Node *root)
{
    // Your code here

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            Node *f = q.front().first;
            int l = q.front().second;
            q.pop();
            m[l].push_back(f->data);
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
        ans.push_back(x.second[0]);
    }
    return ans;
}
vector<int> bottomView(Node *root)
{
    // Your code here

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            Node *f = q.front().first;
            int l = q.front().second;
            q.pop();
            m[l].push_back(f->data);
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
        ans.push_back(x.second[x.second.size() - 1]);
    }
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(7);
    vector<int> a = rightView(root);
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> b = leftView(root);
    for (auto x : b)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> c = topView(root);
    for (auto x : c)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> d = bottomView(root);
    for (auto x : d)
    {
        cout << x << " ";
    }

    return 0;
}
//
//  Node* root;
//     Tree() { root = 0; }

//     void topView()
//     {
//         // queue for holding nodes and their horizontal
//         // distance from the root node
//         queue<pair<Node*, int> > q;

//         // pushing root node with distance 0
//         q.push(make_pair(root, 0));

//         // hd is current node's horizontal distance from
//         // root node l is current left min horizontal
//         // distance (or max in magnitude) so far from the
//         // root node r is current right max horizontal
//         // distance so far from the root node

//         int hd = 0, l = 0, r = 0;

//         // stack is for holding left node's data because
//         // they will appear in reverse order that is why
//         // using stack
//         stack<int> left;

//         // vector is for holding right node's data
//         vector<int> right;

//         Node* node;

//         while (q.size()) {

//             node = q.front().first;
//             hd = q.front().second;

//             if (hd < l) {
//                 left.push(node->data);
//                 l = hd;
//             }
//             else if (hd > r) {
//                 right.push_back(node->data);
//                 r = hd;
//             }

//             if (node->left) {
//                 q.push(make_pair(node->left, hd - 1));
//             }
//             if (node->right) {
//                 q.push(make_pair(node->right, hd + 1));
//             }

//             q.pop();
//         }
//         // printing the left node's data in reverse order
//         while (left.size()) {
//             cout << left.top() << " ";
//             left.pop();
//         }

//         // then printing the root node's data
//         cout << root->data << " ";

//         // finally printing the right node's data
//         for (auto x : right) {
//             cout << x << " ";
//         }
//     }
// };
