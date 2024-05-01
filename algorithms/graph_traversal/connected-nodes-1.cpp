#include <bits/stdc++.h>
using namespace std;

void is_connected(const vector<int> adj_list[], int node)
{

    vector<int> vec = adj_list[node];
    if (vec.size() == 0)
    {
        cout << -1 << endl;
        return;
    }

    sort(vec.begin(), vec.end(), greater<int>());
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        is_connected(adj_list, x);
    }
    return 0;
}