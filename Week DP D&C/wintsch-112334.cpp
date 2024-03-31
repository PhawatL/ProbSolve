#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, y, z;
	cin >> n;
	vector<int> start, stop, weight,vec;
	for (int i = 0; i < n; i++)
	{

		cin >> x >> y >> z;
		start.push_back(x);
		stop.push_back(y);
		weight.push_back(z);
	}
	int stand = n;
	vector<int> pointer(n, -1);
	while (stand--)
	{
		int prof = 0, index = stand;
		for (int i = stand; i < n; i++)
		{
			if (stop[stand] <= start[i] && weight[i] > prof)
			{
				prof = weight[i];
				index = i;
			}
		}
		weight[stand] += prof;
		pointer[stand] = index;
	}
	int ans = INT_MIN;
	int index = 0;
	for (int i = 0; i < n; i++)
	{

		if (ans < weight[i])
		{
			ans = weight[i];
			index = i;
		}
	}
	cout << ans << "\n";
	while (pointer[index] != index)
	{
		vec.push_back(index + 1);
		index = pointer[index];
	}
	vec.push_back(index + 1);
	cout << vec.size() << '\n';
	for (auto it : vec)
		cout << it << " ";
	cout << "\n";
}
