
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n, e;
    cin >> n >> e;
 if (n <= 0 || e <= 0) {
        return 0; 
    }
   vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INT_MAX));
    for (int i = 0; i <= n; i++) {
        adj[i][i] = 0; 
    }
 for (int i = 0; i < e; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        if (n1 > 0 && n1 <= n && n2 > 0 && n2 <= n) { 
            if(adj[n1][n2] > w)
            adj[n1][n2] = w; 
        }
    }



    // Implement the Floyd-Warshall algorithm
    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                    if (adj[i][k] + adj[k][j] < adj[i][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j]; // Update the shortest path
                    }
                }
            }
        }
    }

    int l;
    cin >> l;

      if (l <= 0) {
        return 0; 
    }

    // Process each test case
    while (l--) {
        int src, dest; // Source and destination nodes
        cin >> src >> dest;

        if (src < 1 || src > n || dest < 1 || dest > n) {
            // If source or destination is out of range
            cout << -1 << endl; // Invalid input
        } else if (adj[src][dest] == INT_MAX) {
            // No path exists from source to destination
            cout << -1 << endl;
        } else {
            cout << adj[src][dest] << endl; // Output the minimum cost
        }
    }

    return 0;
}
