#include <bits/stdc++.h>

using namespace std;

#define INF (INT_MAX / 2)

int n, m, x, y, z;

int dijkstra(int start_node, vector<vector<vector<int>>> &v)
{
    vector<int> dis(n + 1, INF);
    dis[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &it : v[u])
        {
            int v = it[0];
            int weight = it[1];

            if (dis[v] > dis[u] + weight)
            {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
    return dis[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<vector<vector<int>>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }

    cout << dijkstra(1, v);
    return 0;
}