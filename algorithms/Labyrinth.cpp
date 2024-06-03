

#include <bits/stdc++.h>
using namespace std;

const int N = 1002;                                        // Although N is defined, it is not being used
int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};


vector<vector<char>> adjMatrix;

// BFS function to find the shortest path between 'A' and 'B'
int bfs(int ri, int ci, int a, int b)
{
    queue<pair<int, int>> q;
    vector<vector<int>> distance(a, vector<int>(b, -1)); // Distance matrix
char d[4]={'L','R','U','D'};
    q.push({ri, ci});
    distance[ri][ci] = 0; // Starting cell distance is 0

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Explore the neighbors
        for (int i = 0; i < 4; i++)
        {
            int dx = directions[i][0];
            int dy = directions[i][1];
            int nx = x + dx;
            int ny = y + dy;

            // Check bounds and if the cell is not visited or a wall
            if (nx >= 0 && nx < a && ny >= 0 && ny < b)
            {
                if (adjMatrix[nx][ny] == 'B')
                {
                  
                    cout<<d[i];
                    return distance[x][y] + 1; // Return the distance to 'B'
                }
                if (adjMatrix[nx][ny] == '.' && distance[nx][ny] == -1)
                {
                    distance[nx][ny] = distance[x][y] + 1; // Update distance
                    cout<<d[i];
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1; // Return -1 if there's no path to 'B'
}

int main()
{
    int a, b;
    cin >> a >> b;

    adjMatrix.resize(a, vector<char>(b)); // Resize the matrix to a x b

    // Read the matrix input
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    int shortestPath = -1;
    // Find the starting point 'A' and call BFS
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (adjMatrix[i][j] == 'A')
            {
                shortestPath = bfs(i, j, a, b);
                break;
            }
        }
        if (shortestPath != -1)
            break;
    }

    if (shortestPath != -1)
    {
        cout <<endl<< "YES" << endl;
        cout << "Shortest path length: " << shortestPath << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    // Print the matrix after BFS (optional)
    cout << "\nMatrix after BFS:\n";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
