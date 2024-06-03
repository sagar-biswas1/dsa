#include <bits/stdc++.h>
using namespace std;

const int max_n = 1005; // Increased size to handle boundary cases
const int max_w = 1005; // Increased size to handle boundary cases
int dp[max_n][max_w];

int knapsack(int n, int weight[], int value[], int w) {
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n - 1] <= w) {
        int opt1 = knapsack(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];
        int opt2 = knapsack(n - 1, weight, value, w);
        dp[n][w] = max(opt1, opt2);
    } else {
        dp[n][w] = knapsack(n - 1, weight, value, w);
    }

    return dp[n][w];
}

int main() {
    int n;
    cin >> n;
    int weight[n], value[n];

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int w;
    cin >> w;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, weight, value, w) << endl;

    // Print the dp table for debugging purposes
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// 4
// 2 3 4 5
// 1 3 5 3
// 8