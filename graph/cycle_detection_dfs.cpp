#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> adj_list[N];
int parents[N];
bool result = false;
void dfs(int parent)
{
//     0
// 1      2
// 0 - 1,2
// 1-0,2
// 2- 0,1
// [, 0, 0]
    visited[parent] = true;

    for (auto child : adj_list[parent])
    {
        if (visited[child] && parents[parent] != child)
        {
            result = true;
        }
        if (!visited[child])
        {
            parents[child] = parent;
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

    memset(visited, false, sizeof(visited));
    memset(parents, -1, sizeof(parents));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

for (int i = 0; i < n; i++)
{
    /* code */
    cout<<"c "<< i <<"-p-> "<< parents[i]<< endl;
}

    cout << "cycle " << result;
    return 0;
}
