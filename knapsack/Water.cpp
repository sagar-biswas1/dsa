#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p;
    cin >> p;
    while (p--)
    {
        int n;
        cin >> n;
        int arr[n];
        int arr2[n];
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            arr[i] = p;
            arr2[i] = p;
        }
        sort(arr2, arr2 + n);
        
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == arr2[n-1]){
            cout<<i<<" ";
        }
         if(arr[i]==arr2[n-2]){
            cout<<i<<" ";
        }
    }
    

    
     cout << endl;
    }
    return 0;
}