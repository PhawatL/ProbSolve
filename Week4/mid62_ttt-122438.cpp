#include <iostream>
#include <vector>
#include <list>

using namespace std;

void checkBipartite(const vector<vector<int>> &adjList, const vector<int> &degree, vector<int> &colors, int start)
{
    list<int> q;
    colors[start] = 1;
    q.push_back(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop_front();

        for (int neighbor : adjList[current])
        {
            if (colors[neighbor] == 0)
            {
                colors[neighbor] = -colors[current];
                q.push_back(neighbor);
            }
            else if (colors[neighbor] == colors[current])
            {
                cout << current + 1 << ' ' << neighbor + 1 << '\n';
                return;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            k++;
        }
    }
    vector<vector<int>> adjList(n);
    vector<int> degree(n);
    int a, b;
    for (int i = 0; i < m; ++i)
    {

        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
        degree[a - 1]++;
        degree[b - 1]++;
    }

    vector<int> colors(n);
    checkBipartite(adjList, degree, colors, b - 4);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            k++;
        }
    }
}