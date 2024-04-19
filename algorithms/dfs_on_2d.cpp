#include <bits/stdc++.h>
using namespace std;

char arr[20][20];
bool visited[20][20];
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

void dfs(int ri, int ci) // Added return type 'void'
{
    cout << ri << " " << ci << "--> " << arr[ri][ci] << endl;
    visited[ri][ci] = true;
    for (int i = 0; i < 4; i++)
    {
        int cc = ri + v[i].first;
        int jj = ci + v[i].second;
        if (validIndex(cc, jj) && visited[cc][jj] == false)
        {

            dfs(cc, jj);
        }
    }
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
    dfs(ri, ci);
    return 0;
}
