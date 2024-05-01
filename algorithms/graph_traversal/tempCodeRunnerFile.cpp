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

int dfs(int ri, int ci)
{
    if (arr[ri][ci] == '#')
        return 0;
    visited[ri][ci] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int cc = ri + v[i].first;
        int jj = ci + v[i].second;
        if (validIndex(cc, jj) && !visited[cc][jj])
        {
            cnt += dfs(cc, jj);
        }
    }
    return cnt;
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) 
        {
            cin >> arr[i][j];
        }
    }

    memset(visited, false, sizeof(visited));

    vector<int> roomCount;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) 
        {
            if (arr[i][j] == '.' && !visited[i][j])
            {
                roomCount.push_back(dfs(i, j));
            }
        }
    }

    sort(roomCount.begin(), roomCount.end());

    for (int i = 0; i < roomCount.size(); i++)
    {
        cout << roomCount[i] << " ";
    }

    return 0;
}
