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
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

int main()
{
    long long l, x, y, z, ans = 0;
    cin >> l;
    vector<long long>v;
    for (int i = 0; i < l; i++) {
        cin >> x;
        v.push_back(x);
    }   

    for (int i = 0; i < l; i++) {
        //cout << "At i = " << i << "\n";
        long long left_count = 0,right_count = 0;
        for (int left = i - 1; left >= 0; left--) {
            if (v[i] < v[left]) left_count++;
        }
        for (int right = i + 1; right < l; right++) {
            if (v[i] < v[right]) right_count++;
        }
        // cout << "left = " << left_count << " right = " << right_count << "\n";
        ans += left_count * right_count;
    }
    cout << ans;
    return 0;
}