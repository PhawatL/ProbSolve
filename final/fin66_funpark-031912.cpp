#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int n, m, x, y, z;


// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    list<int>* adj;

    // A function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    // Constructor
    Graph(int V);

    void addEdge(int v, int w);
    int NumberOfconnectedComponents();
};

// Function to return the number of
// connected components in an undirected graph
int Graph::NumberOfconnectedComponents()
{

    // Mark all the vertices as not visited
    bool* visited = new bool[V];

    // To store the number of connected components
    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            count += 1;
        }
    }

    return count;
}

void Graph::DFSUtil(int v, bool visited[])
{

    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// Add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}


int u_find(vector<int>& parent, int node)
{
    if (parent[node] != node)
    {
        parent[node] = u_find(parent, parent[node]);
    }
    return parent[node];
}

int u_union(vector<int>& parent, vector<int>& rank, int x, int y)
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
    cin >> n >> m;
    vector<vector<int>> v;
    Graph g(n+1);
    g.addEdge(0, 1);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        v.push_back({ z, x, y });
        g.addEdge(x, y);
    }
    if (g.NumberOfconnectedComponents() != 1) {
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end());
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    vector<int> rank(n + 1, 1);
    int ans = 0;
    int idx = 0;
    vector<int>temp;
    for (auto& it : v)
    {

        int u1 = it[1];
        int u2 = it[2];

        if (u_find(parent, u1) != u_find(parent, u2))
        {
            temp.push_back(idx);
            ans += it[0];
            u_union(parent, rank, u1, u2);
        }
        idx++;
    }
    idx = -1;
    //for (auto it : temp) cout << it << " ";
    //cout << "\n";
    for (int i = 0; i < temp.size() - 1; i++) {
        if (temp[i] + 1 != temp[i + 1]) {
            idx = i + 1;
            //cout << "cost " << v[i + 1][0] << "\n";
            break;
        }
    }
    if (idx == -1) idx = temp.back() + 1;
    //cout << "cost " << v[idx][0] << "\n";

    cout << ans + v[idx][0];

    return 0;
}