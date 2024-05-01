#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[6];

int shortest_distance(int src, int dst)
{
    if (src == dst)
        return 0;
    int parent_tracker[6];
    bool visitedNodes[6];
    memset(visitedNodes, false, sizeof(visitedNodes));
    memset(parent_tracker, -1, sizeof(parent_tracker));
    queue<int> q;
    q.push(src);
    visitedNodes[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < adjList[parent].size(); i++)
        {
            int child = adjList[parent][i];
            if (!visitedNodes[child])
            {
                q.push(child);
                visitedNodes[child] = true;
                parent_tracker[child] = parent;
            }
        }
    }

    int x = dst;
    int trip = -1;
    // int flag=-1;
    while (x != -1)
    {

        x = parent_tracker[x];
        // flag++;
        trip++;
    }
    return trip ? trip : -1;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int p;
    cin >> p;
    while (p--)
    {
        int k, l;
        cin >> k>> l;
        cout << shortest_distance(k, l)<<endl;
    }

    return 0;
}