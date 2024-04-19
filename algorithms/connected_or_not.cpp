#include <bits/stdc++.h>
using namespace std;

void is_connected(const vector<int> adj_list[], int p, int q)
{
    
    if(q==q){
        cout<<"NO"<< endl;
        return;
    }
    auto it = find(adj_list[p].begin(), adj_list[p].end(), q);
    if (it != adj_list[p].end())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
    }

      int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        is_connected(adj_list,x, y);
    }
    return 0;
}