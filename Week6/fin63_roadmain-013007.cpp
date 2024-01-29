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

int n, m, a, b, c, d;
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
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	vector<int> rank(n + 1, 1);
	for (int i = 0; i < m; i++) {

		cin >> a >> b >> c >> d;
		if (d) {
			if (u_find(parent, a) != u_find(parent, b))
				u_union(parent, rank, a, b);
		}
		else {
			v.push_back({ c, a, b });
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto& it : v)
	{

		int u1 = it[1];
		int u2 = it[2];

		if (u_find(parent, u1) != u_find(parent, u2))
		{

			ans += it[0];
			u_union(parent, rank, u1, u2);
		}
	}
	cout << ans;
	return 0;
}