#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>
#include <string>
#include <functional>
#include <set>

using namespace std;

int vertex, edge;
#include <queue>

using namespace std;

bool isBipartiteUtil(vector<vector<int>> &adjList, vector<int> &color, int node, int c)
{
    color[node] = c;

    for (int neighbor : adjList[node])
    {
        if (color[neighbor] == -1)
        {
            if (!isBipartiteUtil(adjList, color, neighbor, 1 - c))
                return false;
        }
        else if (color[neighbor] == c)
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &adjList,vector<int>& color, int start_node)
{
    int n = adjList.size();
    color = vector<int>(n, -1);
    if (!isBipartiteUtil(adjList, color, start_node, 0))
        return false;

    return true;
}
int u_find(vector<int> &parent, int node)
{
    if (parent[node] != node)
    {
        parent[node] = u_find(parent, parent[node]);
    }
    return parent[node];
}

int u_union(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int root_x = u_find(parent, x);
    int root_y = u_find(parent, y);

    if (root_x == root_y)
        return 1;

    if (rank[root_x] > rank[root_y])
    {
        parent[root_y] = root_x;
        rank[root_x] += rank[root_y];
    }
    else
    {
        parent[root_x] = root_y;
        rank[root_y] += rank[root_x];
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertex >> edge;
    vector<int> parent(vertex + 1);
    vector<int> rank(vertex + 1, 1);
    vector<vector<int>> adjlist(vertex + 1);

    for (int i = 1; i <= vertex; i++)
        parent[i] = i;
    int a, b, day = -1;
    vector<int> color(vertex + 1, -1);
    for (int i = 0; i < edge; i++)
    {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        if ((day == -1) && (u_union(parent, rank, a, b)))
        {
            if ((color[a] == color[b]) && !isBipartite(adjlist,color,a))
            {
                day = i;
                break;
            }
        }
    }
    if (day == -1)
        day = edge;

    cout << day << "\n";

    return 0;
}
