#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];

void dusInitialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }

    // par[1] = 3;
    // par[2] = 1;
}

int find(int node)
{
    if (par[node] == -1)
        return node;
    int l = find(par[node]);
    par[node] = l;
    return l;
}

// void dsu_union(int a, int b)
// {
//     int leaderA = find(a);
//     int leaderB = find(b);

//     par[leaderA] = leaderB;
// }
void dsu_union_by_level(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
void dsu_union_by_size(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {

        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

void union_by_rank(int a,int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderA] < level[leaderB])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}

int main()
{
    dusInitialize(7); // Initialize with the number of elements you intend to use
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);
    union_by_rank(3, 4);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    cout << find(0) << endl;
    cout << find(1) << endl;
    cout << find(2) << endl;
    cout << find(5) << endl;

    return 0;
}
