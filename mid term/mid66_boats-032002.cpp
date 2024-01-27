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

int n, m, x;
multiset<int> xi;
vector<int> yi;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        xi.insert(x);
    }


    for (int i = 0; i < m; i++)
    {
        cin >> x;
        yi.push_back(x);
    }
    int ans = 0;
    for (auto ship : yi)
    {

        auto tmp = xi.lower_bound(ship);

        if (tmp == xi.end())
        {
            cout << ans;
            return 0;
        }
        else {
            xi.erase(tmp);
        }
        ans++;


    }
    cout << ans;
    return 0;
}