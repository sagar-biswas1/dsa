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

int main()
{

    int n, e;
    cin >> n >> e;
    initialize_dsu(n);

    bool cycle = false;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find_leader(a);
        int leaderB = find_leader(b);

        if (leaderA == leaderB)
            cycle = true;
        else
            dsu_union_by_size(a, b);
    }

    if (cycle)
        cout << "cycle found" << endl;
    else
        cout << "cycle not found" << endl;


for (int i = 0; i < e; i++)
{
    cout<<parent[i]<<endl;
}

    return 0;
}