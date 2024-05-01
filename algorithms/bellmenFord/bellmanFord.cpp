#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int n, e, w;
    Edge(int n, int e, int w)
    {
        this->n = n;
        this->e = e;
        this->w = w;
    }
};

const int N = 1e5 + 5;

int dis[N];
int main()
{
    int a, b;
    cin >> a >> b;
    vector<Edge> edgeList;
    while (b--)
    {
        int n, e, w;
        cin >> n >> e >> w;
        edgeList.push_back(Edge(n, e, w));
        //if undirected
        // edgeList.push_back(Edge(e, n, w));
    }

    for (int i = 0; i < a; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 1; i <= a - 1; i++)
    {
        /* code */
        for (Edge elem : edgeList)
        {
            int u = elem.n;

            int v = elem.e;
            int c = elem.w;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                cout << v << endl;
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge elem : edgeList)
    {
        int u = elem.n;

        int v = elem.e;
        int c = elem.w;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
        }
    }

    for (int i = 0; i < a; i++)
    {
        /* code */
        cout << " i ->" << dis[i] << " " << endl;
    }

    return 0;
}