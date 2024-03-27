#include <bits/stdc++.h>
using namespace std;

void insertHeap(vector<int> &v, int x)
{

    v.push_back(x);

    int cur_index = v.size() - 1;

    while (cur_index != 0)
    {
        int parentIndex = (cur_index - 1) / 2;
        if (v[parentIndex] < v[cur_index])
        {
            swap(v[parentIndex], v[cur_index]);
            cur_index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    while (true)
    {
        int left_index = cur * 2 + 1;
        int right_index = cur * 2 + 2;
        int last_index = v.size() - 1;

        if (left_index <= last_index && right_index <= last_index)
        {
            if (v[left_index] >= v[right_index] && v[left_index] > v[cur])
            {
                swap(v[left_index], v[cur]);
                cur = left_index;
            }
            else if (v[left_index] <= v[right_index] && v[right_index] > v[cur])
            {
                swap(v[right_index], v[cur]);
                cur = right_index;
            }
            else
            {
                break;
            }
        }
        else if (left_index <= last_index)
        {
            if (v[left_index] > v[cur])
            {
                swap(v[left_index], v[cur]);
                cur = left_index;
            }
            else
            {
                break;
            }
        }
        else if (right_index <= last_index)
        {
            if (v[right_index] > v[cur])
            {
                swap(v[right_index], v[cur]);
                cur = right_index;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertHeap(v, x);
    }

delete_heap(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}