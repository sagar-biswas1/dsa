#include <bits/stdc++.h>
using namespace std;

char arr[1000][1000];
bool visited[1000][1000];
int r, c;

bool validIndex(int i, int j)
{
    if (i < 0 || i >= r)
    {
        return false;
    }
    if (j < 0 || j >= c)
    {
        return false;
    }

    return true;
}

vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
string dfs(int ri, int ci)
{
    if (arr[ri][ci] == '#')
        return "NO";
    if (arr[ri][ci] == 'B')
        return "YES";
    visited[ri][ci] = true;
    string str;
    for (int i = 0; i < 4; i++)
    {
        int cc = ri + v[i].first;
        int jj = ci + v[i].second;

        if (validIndex(cc, jj) && !visited[cc][jj])
        {
            str = dfs(cc, jj);
            if (str == "YES")
                return "YES"; 
        }
    }
    return "NO"; 
}
int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) // Corrected the loop condition
        {
            cin >> arr[i][j];
        }
    }

    int ri, ci;
    cin >> ri >> ci;

    // Removed memset for arr, it's not needed here

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) // Corrected the loop condition
        {
            if (arr[i][j] == 'A')
                cout << dfs(i, j) << endl;
        }
    }

    return 0;
}
