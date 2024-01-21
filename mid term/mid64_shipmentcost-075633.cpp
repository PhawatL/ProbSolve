#include <bits/stdc++.h>

using namespace std;

// #define INT_MAX 2000000000

int n, m, s, t, x, y;
vector<int> warehouse;
unordered_map<int, int> factory;
vector<int> factory_list;
void printAdjacencyList(const vector<list<int>> &adjacencyList)
{
    for (size_t i = 0; i < adjacencyList.size(); ++i)
    {
        cout << "Vertex " << i << ": ";
        for (int neighbor : adjacencyList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
void bfs(int start_node, vector<list<int>>& lst,vector<bool>& visited){
    
    queue<int>q;
    q.push(start_node);
    int cnr = 0,ccr = 1;
    int level = 0;
    // cout << "level " << level << "\n";
    while(!q.empty()){

        if (factory[start_node] == 1) {
            cout << level << "\n";
            return;
        }
        if (!visited[start_node]){
            visited[start_node] = true;
            for (auto it:lst[q.front()]){
                cnr++;
                q.push(it);
            } 
            // cout << q.front() << " ";    
        } 
        
        q.pop();
        start_node = q.front();
        ccr--;
        if (ccr == 0){
            ccr = cnr;
            cnr = 0;
            level++;
            // cout << "\nlevel " << level << "\n";
        }
    }

}

void bfs2(int node, vector<list<int>> &lst, vector<bool> &visited, vector<int> &level)
{
    queue<int> q;
    level[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (visited[node])
            continue;
        visited[node] = true;
        for (auto &it : lst[node])
        {
            q.push(it);
            level[it] = min(level[it], level[node] + 1);
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    vector<list<int>> adjacentcy_list(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adjacentcy_list[x].push_back(y);
        adjacentcy_list[y].push_back(x);
    }

    for (int i = 0; i < s; i++)
    {
        cin >> x;
        warehouse.push_back(x);
        factory[x] = 1;
    }

    for (int i = 0; i < t; i++)
    {
        cin >> x;
        
        factory_list.push_back(x);
    }

    // printAdjacencyList(adjacentcy_list);
    
    // cout << factory_list.size() << " : " << warehouse.size() << "\n";
    if (factory_list.size() < warehouse.size())
    {
        // cout << "case : 1 \n";

        for (auto fac : factory_list)
        {
            // cout << "warehouse : " << wh << "\n";
            vector<bool> visited(n + 1, false);
            bfs(fac, adjacentcy_list, visited);
        }
    } // few factory
    else

    {
        // cout << "case : 2 \n";
        vector<int> level(n + 1, INT_MAX);
        for (auto wh : warehouse)
        {
            // cout << "warehouse : " << wh << "\n";
            vector<bool> visited(n + 1, false);

            bfs2(wh, adjacentcy_list, visited, level);
        }

        for (auto fac : factory_list)
        {

            cout << level[fac] << "\n";
        }
    }
    return 0;
}