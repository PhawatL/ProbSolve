#include <bits/stdc++.h>

using namespace std;

int n, l, x;
int func(vector<int> &v, vector<vector<int>> &memo, int start, int end)
{
	if (end - start == 1)
		return 0;
	if (memo[start][end] != -1)
		return memo[start][end];
	int cost = v[end] - v[start];
	int additionCost = INT_MAX;
	for (int i = start + 1; i < end; i++)
		additionCost = min(additionCost, func(v, memo, start, i) + func(v, memo, i, end));
	memo[start][end] = cost + additionCost;
	return memo[start][end];
}
int main()
{
	while (cin >> l && l)
	{
		cin >> n;
		vector<int> v{0};
		vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
		}
		v.push_back(l);
		cout << "The minimum cutting is " << func(v, memo, 0, n+1) << ".\n";
	}
}