#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, q;

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
    cin >> n >> q;
    vector<vector<int>> v;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    vector<int> rank(n + 1, 1);
    int ans = 0;
    for (int i = 0; i < q; i++)
    {   
        char c;
        cin >> c >> x >> y;
        
        if (c == 'q'){
            if (u_find(parent,x) == u_find(parent,y)){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }else{
            if (u_find(parent,x) != u_find(parent,y))
                u_union(parent, rank, x, y);
            
        }
    }

    return 0;
}