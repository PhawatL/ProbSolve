#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& lst, vector<bool> &visited, int start_node)
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    while (!q.empty())
    {
        start_node = q.front();
        q.pop();
        for (const auto i : lst[start_node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    int x, y, vertex, edge;
    cin >> vertex >> edge;

    vector<vector<int>> adjacencyList(vertex);
    for (int i = 0; i < edge; i++)
    {

        cin >> x >> y;
        adjacencyList[x - 1].push_back(y - 1);
        adjacencyList[y - 1].push_back(x - 1);
    }
    vector<bool> visited(vertex, false);
    int ans = 0;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjacencyList, visited, i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}