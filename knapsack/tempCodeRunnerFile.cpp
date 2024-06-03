#include <bits/stdc++.h>
using namespace std;
const int max_n = 1005; // Increased size to handle boundary cases
const int max_w = 1005; // Increased size to handle boundary cases
int dp[max_n][max_w];

// bool isSubSetSum=false;

bool knapsack(int n, int value[], int w)
{

    if (n == 0)
    {
        if (w == 0)
            return true;
        else
            return false;
    }
if(dp[n][w] != 0) return dp[n][w];
    if (value[n - 1] <= w)
    {
        bool v1 = knapsack(n - 1, value, w - value[n - 1]);
        bool v2 = knapsack(n - 1, value, w);
        dp[n][w]= v1 || v2;
        return v1 || v2;
    }
    else
    {
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

    cout << knapsack(n, arr, w);

    return 0;
}