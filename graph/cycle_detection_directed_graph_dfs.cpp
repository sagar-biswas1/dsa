#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
bool path_visited[N];
vector<int> adj_list[N];
int parents[N];
bool result = false;
void dfs(int parent)
{
    visited[parent] = true;
    path_visited[parent] = true;
    for (auto child : adj_list[parent])
    {
        if (path_visited[child])
        {
            result = true;
        }
        if (!visited[child])
        {
            parents[child] = parent;
            dfs(child);
        }
    }
    path_visited[parent] = false;
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
        // adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(path_visited, false, sizeof(path_visited));
    memset(parents, -1, sizeof(parents));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    cout << "cycle " << result;
    return 0;
}
