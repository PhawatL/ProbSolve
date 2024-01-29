#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, z;

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

double d(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<vector<int>> v0;
    vector<vector<double>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v0.push_back({x, y});
    }

    for (double i = 0; i < n - 1; i++)
    {
        for (double j = i + 1; j < n; j++)
        {
            v.push_back({d(v0[i][0],v0[i][1],v0[j][0],v0[j][1]),i,j});
            v.push_back({d(v0[i][0],v0[i][1],v0[j][0],v0[j][1]),j,i});
        }
    }

    sort(v.begin(), v.end());
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    vector<int> rank(n + 1, 1);
    vector<double>ans;
    for (auto &it : v)
    {

        int u1 = it[1];
        int u2 = it[2];

        if (u_find(parent, u1) != u_find(parent, u2))
        {

            ans.push_back(it[0]);
            u_union(parent, rank, u1, u2);
        }
    }
    double a = 0.;
    for (int i = 0;i<ans.size()-1;i++){
        a += ans[i];
    }

    printf("%.4lf", a);

    return 0;
}