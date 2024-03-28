#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Descending //max heap
    //  priority_queue<int> qu;

    // ascending // min heap
    priority_queue<int, vector<int>, greater<int>> qu;
    while (true)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            int v;
            cin >> v;
            qu.push(v);
        }
        else if (x == 1)
        {
            qu.pop();
        }

        else if (x == 2)
        {
            cout << qu.top() << endl;
        }

        else
        {
            break;
        }
    }

    return 0;
}