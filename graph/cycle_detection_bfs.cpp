#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> adj_list[N];
int parents[N];
bool result = false;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        cout << parent << endl;
        q.pop();
        for (int i = 0; i < adj_list[parent].size(); i++)
        {
            int child = adj_list[parent][i];

            if (visited[child] && parents[parent] != child)
            {
                result = true;
            }
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parents[child] = parent;
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

    memset(visited, false, sizeof(visited));
    memset(parents, -1, sizeof(parents));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

cout<<"cycle " << result;
    return 0;
}
