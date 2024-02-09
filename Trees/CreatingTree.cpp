#include <bits/stdc++.h>
using namespace std;
void addEdge(int x, int y, vector<vector<int>> &adj)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void printparents(int root, vector<vector<int>> &adj, int parent)
{
    if (parent == 0)
    {
        cout << root << "--Root" << endl;
    }
    else
    {
        cout << root << "--" << parent << endl;
    }
    for (auto x : adj[root])
    {
        if (x != parent)
        {
            printparents(x, adj, root);
        }
    }
}
void printchildren(int root, vector<vector<int>> &adj)
{

    queue<int> q;
    q.push(root);
    vector<int> vis(adj.size(), 0);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        vis[f] = 1;
        int s = adj[f].size();
        cout << f << "-->";
        for (auto x : adj[f])
        {
            if (vis[x] == 0)
            {
                cout << x << " ";
                q.push(x);
            }
        }
        cout << endl;
    }
}
void printleaves(vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i].size() == 1)
        {
            cout << i << " ";
        }
    }
}
void printdegree(int root, vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (i == root)
        {
            cout << i << " "
                 << "-->" << adj[i].size() - 1 << endl;
        }
        else
        {
            cout << i << " "
                 << "-->" << adj[i].size() - 1 << endl;
        }
    }
}
int main()
{
    int N;
    cin >> N;
    int root;
    cin >> root;
    vector<vector<int>> adj(N + 1, vector<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int x, y;
        cin >> x;
        cin >> y;
        addEdge(x, y, adj);
    }
    cout << "Parents are--" << endl;
    printparents(root, adj, 0);
    cout << "Children are--" << endl;
    printchildren(root, adj);
    cout << "Leaves are--" << endl;
    printleaves(adj);
    cout << "Degree are--" << endl;
    printdegree(root, adj);
    return 0;
}