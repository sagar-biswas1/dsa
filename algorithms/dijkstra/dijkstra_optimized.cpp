#include <bits/stdc++.h>
using namespace std;
const int N = 100;

vector<pair<int, int>> adj_list[N];

int dis[N];
class cmp{
  public:
    bool operator()(pair<int, int>a,pair<int, int> b){
       return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.top();
        q.pop();
        int node = parent.first;
        int cost = parent.second;

        for (int i = 0; i < adj_list[node].size(); i++)
        {
            pair<int, int> child = adj_list[node][i];

            int child_node = child.first;
            int child_cost = child.second;
            if (cost + child_cost < dis[child_node])
            {
                // path relax;
                dis[child_node] = cost + child_cost;
                q.push({child_node, dis[child_node]});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << i << "-> " << dis[i] << endl;
    }

    return 0;
}

