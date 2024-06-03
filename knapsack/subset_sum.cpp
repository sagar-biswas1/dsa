#include <bits/stdc++.h>
using namespace std;
const int max_n = 1005; // Increased size to handle boundary cases
const int max_w = 1005; // Increased size to handle boundary cases
int dp[max_n][max_w];

// bool isSubSetSum=false;

int knapsack(int n, int value[], int w)
{

    if (n == 0)
    {
        if (w == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][w] != -1)
        return dp[n][w];
    if (value[n - 1] <= w)
    {
        int v1 = knapsack(n - 1, value, w - value[n - 1]);
        int v2 = knapsack(n - 1, value, w);
        dp[n][w] = v1 + v2;

        return v1 + v2;
    }
    else
    {
        dp[n][w]=knapsack(n - 1, value, w);
        return knapsack(n - 1, value, w);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int w;
    cin >> w;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, arr, w) << endl;

    return 0;
}