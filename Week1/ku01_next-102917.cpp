#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;


int main()
{
	int loop,tmp,ans;
	set<int> myset;
	ans = 0;
	cin >> loop;
	vector<int> scr;
	vector<pair<int,int>> sim;
	for (int i = 0; i < loop; i++) {
		
		cin >> tmp;
		sim.push_back(make_pair(i+1,i+1));
		scr.push_back(tmp);
	}
	int size = scr.size();
	while (myset.size() < size) {

		for (int i = 0; i < size; i++) {

			sim[scr[i] - 1].second = sim[i].first;

		}
		for (int i = 0; i < size; i++) {

			sim[i].first = sim[i].second;
			if (sim[i].first == i + 1)
				myset.insert(i + 1);

		}ans++;

	}
	cout << ans;
	return 0;
}