#include <bits/stdc++.h>
using namespace std;

const int max_n = 1005;
int dp[max_n][1005]; // Adjust the array dimension

int knapsack(int n, int value[], int w) {
    if (n == 0) {
        if (w == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][w] != -1)
        return dp[n][w];
    if (value[n - 1] <= w) {
        int v1 = knapsack(n - 1, value, w - value[n - 1]);
        int v2 = knapsack(n - 1, value, w);
        dp[n][w] = v1 + v2;
        return v1 + v2;
    }
    else {
        dp[n][w] = knapsack(n - 1, value, w);
        return dp[n][w];
    }
}

int main() {
    int p;
    cin >> p;
    while (p--) {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // Initialize DP array
        memset(dp, -1, sizeof(dp));
        int x = knapsack(n, arr, 1000 - m); // Pass n instead of n - 1
        if (x) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
