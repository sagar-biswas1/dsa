#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
cout<<i<<"--> "; 
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    if (mat[3][4] == 1)
        cout << "connection ache" << endl;
   
    return 0;
}