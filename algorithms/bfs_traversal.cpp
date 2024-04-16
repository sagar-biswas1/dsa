#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_nodes[1005];

void bfs(int src){
    queue <int> q;
    q.push(src);
    visited_nodes[src]=true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        cout<< p <<" ->";
        // for (int i = 0; i < adj_list[p].size(); i++)
        // {
        //     int child = adj_list[p][i];
        //     cout<< child<<" ";
        // }
        for (auto child : adj_list[p])
        {
           if(!visited_nodes[child]){
             q.push(child);
    visited_nodes[child]=true;
           }
           
        }
        
    }
}
int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited_nodes, false, sizeof(visited_nodes));
    int src;
    cin >> src;
    bfs(src);
    return 0;
}