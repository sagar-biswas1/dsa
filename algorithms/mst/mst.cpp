#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

void initialize_dsu(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int find_leader(int n)
{
    if (parent[n] == -1)
        return n;
    int leader = find_leader(parent[n]);

    parent[n] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = find_leader(node1);
    int leaderB = find_leader(node2);

    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

class Edge
{

public:
    int n1, n2, w;
    Edge(int n1, int n2, int w)
    {
        this->n1 = n1;
        this->n2 = n2;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{

    int node, edge;
    cin >> node >> edge;

    initialize_dsu(node);
    vector<Edge> edgeList;

    while (edge--)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        edgeList.push_back(Edge(n1, n2, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    int totalCost = 0;
    for (auto ed : edgeList)
    {
        int leaderA = find_leader(ed.n1);
        int leaderB = find_leader(ed.n2);
        if (leaderA == leaderB)
            continue;
        else
        {

            dsu_union_by_size(ed.n1, ed.n2);
            totalCost += ed.w;
        }
    }

cout<< totalCost;
    return 0;
}