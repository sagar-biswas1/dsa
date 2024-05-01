#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_nodes[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;

    q.push(src);

    visited_nodes[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int p = q.front();

        q.pop();

        int l = level[p];

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
                q.push(child);
                visited_nodes[child] = true;
                level[child] = l + 1;
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

    int l;
    cin >> l;
    cout << adj_list[l].size();
    // for (int i = 0; i < adj_list[l].size(); i++)
    // {
    //     /* code */
    //     cout<< adj_list[l][i]<<" ";
    // }

    // bfs(0);
    // for (int i = n; i >= 0; i--)
    // {
    //     if(level[i] == l)
    //     cout << i << " -> " << i << endl;
    // }
    {
        /* code */
    }

    return 0;
}