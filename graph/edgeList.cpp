#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> arr;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

for (pair<int, int>p:arr)
{
    cout<< p.first << " " << p.second << endl;
}

    return 0;
}