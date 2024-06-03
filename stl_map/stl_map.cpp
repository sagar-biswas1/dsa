#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp.insert({"sam", 1});
    mp.insert({"ram", 1});
    if (mp.count("sa"))
    {
        cout << mp["sam"] << endl;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << endl;
    }
    return 0;
}