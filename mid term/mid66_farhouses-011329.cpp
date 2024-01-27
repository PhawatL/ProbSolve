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

int n, k, l, x;
vector<int> v;
int main()
{

    cin >> n >> k >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int max_l = 0;

    for (int i = 0; i < n - k - l; i++)
    {
        // cout << v[i + 3] << " " << v[i] << "\n";
        max_l = max(max_l, v[i + k + l] - v[i]);
    }

    cout << max_l;

    return 0;
}
