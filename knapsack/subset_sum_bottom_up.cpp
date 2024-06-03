#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int s;
    cin >> s;
    bool dp[n][s];
    dp[0][0] = true;

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (value[i - 1] <= j)
            {
                bool opt1 = dp[i - 1][j - value[i - 1]];
                bool opt2 = dp[i - 1][j];
                dp[i][j] = opt1 || opt2;
            }
            else
            {
                  bool opt2 = dp[i - 1][j];
                dp[i][j] = opt2;
            }
        }
    }

    if(dp[n][s]){
        cout<<"YES";
    }else{
        cout<< "NO";
    }

    return 0;
}