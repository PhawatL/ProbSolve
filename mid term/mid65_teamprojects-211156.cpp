#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y;

bool dfs(vector<vector<int>> &adjlist, vector<int> &color_list, vector<int> &counter, int node, int color)
{
    if (color_list[node] != 0)
    {
        return color_list[node] == color;
    }
    else
    {
        color_list[node] = color;
        for (auto &it : adjlist[node])
        {
            if (counter[it] >= k)
                continue;
            if (!dfs(adjlist, color_list, counter, it, -color))
                return false;
        }
    }
    return true;
}

int main()
{

    cin >> n >> m >> k;
    vector<int> counter(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        counter[x]++;
        counter[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> color_list(n + 1, 0);
    bool is_bipartite = true;

    for (int node = 1; node <= n; ++node)
    {
        if (counter[node] < k)
        {
            if (!dfs(adj, color_list, counter, node, 1))
            {
                is_bipartite = false;
                break;
            }
            break;
        }
    }
    if (is_bipartite)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}
