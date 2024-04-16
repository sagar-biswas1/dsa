#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_nodes[1005];
int level[1005];
int parent_tracker[1005];

void bfs(int src, int des)
{
    // queue<int> q;
    queue<pair<int, int>> q;
    // q.push(src);
    q.push({src, 0});
    visited_nodes[src] = true;
    // level[src] = 0;
    while (!q.empty())
    {
        // int p = q.front();
        pair<int, int> par = q.front();
        q.pop();
        int p = par.first;
        int level = par.second;
        // if (p == des)
        // {
        //     cout << level << endl;
        // }
        // cout << p << " ->";
        // for (int i = 0; i < adj_list[p].size(); i++)
        // {
        //     int child = adj_list[p][i];
        //     cout<< child<<" ";
        // }
        for (auto child : adj_list[p])
        {
            if (!visited_nodes[child])
            {
                q.push({child, level + 1});
                visited_nodes[child] = true;
                parent_tracker[child] = p;
                // level[child] =level[p]+1;
            }
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited_nodes, false, sizeof(visited_nodes));
    memset(level, -1, sizeof(level));
    memset(parent_tracker, -1, sizeof(parent_tracker));
    int src, des;
    cin >> src >> des;
    bfs(src,6);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << level[i] << endl;
    // }
    // {
    //     /* code */
    // }
    int x = des;
    while (x != -1)
    {
        cout << x << " -> ";
        x = parent_tracker[x];
    }
    return 0;
}