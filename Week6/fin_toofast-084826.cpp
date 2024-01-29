#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

int n, m, l, x, y, z, w, gob_ans = INF;

void dijkstra(int start_node, vector<vector<vector<int>>> &v, vector<int> &dis)
{
    dis[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &it : v[u])
        {
            int node = it[0];
            int weight = it[1];
            if (it[2])
                continue;
            if (dis[node] > dis[u] + weight)
            {
                dis[node] = dis[u] + weight;
                pq.push({dis[node], node});
            }
        }
    }
}
void dijkstra_h(int start_node, vector<vector<vector<int>>> &v, vector<int> &dis, vector<int> &com_dis)
{
    dis[start_node] = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, start_node,0});

    while (!pq.empty())
    {
        int u = pq.top()[1];
        int h = pq.top()[2];
        pq.pop();
        if (h)
        {
            gob_ans = min(gob_ans, dis[u] + com_dis[u]);
            dis[u] = INF;
            continue;
        }
        for (auto &it : v[u])
        {
            int node = it[0];
            int weight = it[1];

            if (dis[node] > dis[u] + weight)
            {
                dis[node] = dis[u] + weight;
                pq.push({dis[node], node, it[2]});
            }
        }
    }
    gob_ans = min(gob_ans,dis[n]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    vector<vector<vector<int>>> v(n + 1);
    vector<vector<int>> h;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z >> w;
        v[x].push_back({y, z, w});
        v[y].push_back({x, z, w});
    }
    vector<int> dis_fs(n + 1, INF);
    vector<int> dis_fe(n + 1, INF);
    
    dijkstra(n, v, dis_fe);
    dijkstra_h(1, v, dis_fs,dis_fe);
    if (gob_ans == INF)
        cout << -1;
    else
        cout << gob_ans;

    return 0;
}