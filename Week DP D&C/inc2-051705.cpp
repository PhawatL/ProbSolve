#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,x;
	cin >> n;
	vector<int>v;
	for (int i = 0;i<n;i++){
		cin >> x;
		v.push_back(x);
	}
	vector<int>ans;
	ans.push_back(v[0]);
	for (const auto &it:v){
		if (it > ans.back())
			ans.push_back(it);
		else{
			int idx = lower_bound(ans.begin(),ans.end(),it) - ans.begin();
			ans[idx] = it;
		}

	}
	cout << ans.size();
}
