#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

 vector<int> adj_list[N];
  bool visited_nodes[N];

void dfs(int src)
{
    cout << src << endl;
    visited_nodes[src] = true;

    for (int child : adj_list[src])
    {
        if (!visited_nodes[child])
        {
            dfs(child);
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
    dfs(5);
    return 0;
}