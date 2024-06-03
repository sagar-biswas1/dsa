#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1][n2] = w;
    }

for (int k = 0; k < n; k++)
{
    for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if(adj[i][k]+adj[j][k]< adj[i][j]){
            aj[i][j]=adj[i][k]+adj[j][k];
        }
    }
    
}
}




    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}