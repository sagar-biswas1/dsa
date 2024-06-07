#include <bits/stdc++.h>
using namespace std;

string can_reach(int n) {
    if (n == 1) return "YES";
    
    vector <bool> dp(n + 1, false);
    dp[1] = true;

    for (int i = 1; i <= n; ++i) {
        if (dp[i]) {
            if (i + 3 <= n) {
                dp[i + 3] = true;
            }
            if (i * 2 <= n) {
                dp[i * 2] = true;
            }
        }
    }

    return dp[n] ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << can_reach(n) << endl;
    }

    return 0;
}
