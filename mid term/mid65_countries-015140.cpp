#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

int r, c, x, y,startx,starty,endx,endy,num_c = 0;

bool validp(int x, int y)
{
    if (x <= 0 || x > r || y <= 0 || y > c)
        return false;
    return true;
}

int bfs(int start_node,int end_node, vector<unordered_set<int>>& lst){
    
    queue<int>q;
    q.push(start_node);
    vector<int>level(num_c+1,-1);
    level[start_node] = 0;

    // cout << "level " << level << "\n";
    while(!q.empty()){

        start_node = q.front();
        q.pop();

        for (auto it : lst[start_node]) {
            if (level[it] != -1) {
                continue;
            }
            q.push(it);
            level[it] = level[start_node] + 1;
            if (it == end_node)
                return level[it];

        }


    }


    return -69;
}



int main()
{

    cin >> r >> c >> startx >> starty >> endx >> endy;
    // get input
    vector<vector<int>> m(r+1, vector<int>(c+1, 0));
    vector<unordered_set<int>> adj(r * c + 1);
    
    for (int i = 0; i < r; i++)
    {

        for (int j = 0; j < c; j++)
        {
            cin >> x;
            m[i+1][j+1] = x;
            num_c = max(num_c, x);
        }
    }
    //cout << "zadsfas\n";
    // gen border
    for (int i = 1; i <= r; i++)
    {

        for (int j = 1; j <= c; j++)
        {

            if (validp(i, j + 1))
                adj[m[i][j]].insert(m[i][j + 1]);
            if (validp(i, j - 1))
                adj[m[i][j]].insert(m[i][j - 1]);
            if (validp(i + 1, j))
                adj[m[i][j]].insert(m[i + 1][j]);
            if (validp(i - 1, j))
                adj[m[i][j]].insert(m[i - 1][j]);
        }
    }
    //cout << "asdasdasas\n";
    // for (int i = 0;i<adj.size();i++){
    //     if (adj[i].size() == 0)
    //         continue;
    //     cout << i  << " : ";
    //     for (auto it:adj[i])
    //         cout << it << " ";
    //     cout << "\n";

    // }
    int start = m[startx][starty];
    int end = m[endx][endy];
    //cout << start << " " << end << "\n";
    cout << bfs(start, end, adj);

    return 0;
}
