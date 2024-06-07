// #include <bits/stdc++.h>
// using namespace std;
// const int max_n = 2005;
// const int max_w = 2005;
// bool dp[max_n][max_w] ;

// bool isEqualSum(int n, int arr[], int w)
// {
//     if (n == 0)
//     {
//         if (w == 0)
//             return true;
//         else
//             return false;
//     }
//     if (dp[n][w]==true)
//         return dp[n][w];

//     if (arr[n] <= w)
//     {
//         bool r1 = isEqualSum(n - 1, arr, w - arr[n]);
//         bool r2 = isEqualSum(n - 1, arr, w);
//         dp[n][w] = r1 || r2;
//         return r1 || r2;
//     }
//     else
//     {
//         dp[n][w] = isEqualSum(n - 1, arr, w);
//         return isEqualSum(n - 1, arr, w);
//     }
// }

// int main()
// {
//     int p;
//     cin >> p;
//     while (p--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];
//         int w = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             w += arr[i];
//         }
//         memset(dp, false, sizeof(dp));
//         if (w % 2 == 0)
//         {
//             if (isEqualSum(n - 1, arr, w / 2))
//             {
//                 cout << "YES" << endl;
//             }
//             else
//             {
//                 cout << "NO" << endl;
//             }
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int max_n = 2005;
// const int max_w = 2005;
// int dp[max_n][max_w];

// bool isEqualSum(int n, int arr[], int w) {
//     // Base cases
//     if (w == 0)
//         return true;
//     if (n == 0)
//         return false;

//     if (dp[n][w] != -1)
//         return dp[n][w];

//     if (arr[n-1] <= w) {
//         bool include = isEqualSum(n - 1, arr, w - arr[n-1]);
//         bool exclude = isEqualSum(n - 1, arr, w);
//         dp[n][w] = include || exclude;
//         return dp[n][w];
//     } else {
//         dp[n][w] = isEqualSum(n - 1, arr, w);
//         return dp[n][w];
//     }
// }

// int main() {
//     int p;
//     cin >> p;
//     while (p--) {
//         int n;
//         cin >> n;
//         int arr[n];
//         int w = 0;
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//             w += arr[i];
//         }

//             memset(dp, -1, sizeof(dp));  
//         if (w % 2 == 0) {
//             if (isEqualSum(n, arr, w / 2)) {
//                 cout << "YES" << endl;
//             } else {
//                 cout << "NO" << endl;
//             }
//         } else {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int max_n = 2005;
const int max_w = 2005;
bool dp[max_n][max_w];

bool isEqualSum(int n, int arr[], int w) {
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;  // A sum of 0 is always possible
    }
    for (int j = 1; j <= w; ++j) {
        dp[0][j] = false;  // With 0 elements, no positive sum is possible
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int p;
    cin >> p;
    while (p--) {
        int n;
        cin >> n;
        int arr[n];
        int w = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            w += arr[i];
        }
        if (w % 2 == 0) {
            memset(dp, false, sizeof(dp));
            if (isEqualSum(n, arr, w / 2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
