
// void dijkstra(int src)
// {
//     queue<pair<int, int>> q;
//     q.push({src, 0});
//     distance[src] = 0;

//     while (!q.empty())
//     {
//         pair<int, int> parent = q.front();
//         q.pop();
//         int node = parent.first;
//         int cost = parent.second;

//         for (int i = 0; i < adj_list[node].size(); i++)
//         {
//             pair<int, int> child = adj_list[node][i];

//             int child_node = child.first;
//             int child_cost = child.second;
//             if (cost + child_cost < distance[child_node])
//             {
//                 // path relax;
//                 distance[child_node] = cost + child_cost;
//                 q.push({child_node, distance[child_node]});
//             }
//         }
//     }
// }