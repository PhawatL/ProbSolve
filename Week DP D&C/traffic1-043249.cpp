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
#include <iomanip>
#include <deque>
#include <cstdlib>
#include "traffic.h"

using namespace std;

int n,k;
vector<vector<int>> ans;
void helper(int x,int start,int end) {

    int mid = (start + end) / 2;
    if (start + 1 == mid) {
        if (traffic_query(x, start, x, mid) == 2)
            ans.push_back({ x, start, x, mid });
    }
    if (mid + 1 == end) {
        if (traffic_query(x, mid, x, end) == 2)
            ans.push_back({ x, mid, x, end});
        return;
    }
    if (traffic_query(x, start, x, mid) == (mid - start + 1))
        return helper(x, start, mid);
    return helper(x, mid, end);

}

void helper2(int y, int start, int end) {
   
    int mid = (start + end) / 2;
    // cout << start << " " << mid << " " << end << "\n";
    if (start + 1 == mid) {
        if (traffic_query(start, y, mid, y) == 2)
            ans.push_back({ start, y, mid, y });
    }
    if (mid + 1 == end) {
        // cout << "traffic_query(mid, y, end, y) " << traffic_query(mid, y, end, y) << "\n";
        if (traffic_query(mid, y, end, y) == 2)
            ans.push_back({ mid, y, end, y });
        return;
    }
    if (traffic_query(start, y, mid, y) == (mid - start + 1))
        return helper2(y, start, mid);
    return helper2(y, mid, end);

}


int main()
{
    traffic_init(&n, &k);
    vector<vector<int>>v;
    // vertical run
    for (int i = 1; i <= n; i++) {

        if (traffic_query(i, 1, i, n) == n) {
            // cout << "Found At " << "(" << i << ", 1" << ")" << " -> " << "(" << i << ", " << n << ")" << "\n";
            helper(i,1,n);
        }

    }
    // horizontal run
    for (int i = 1; i <= n; i++) {

        if (traffic_query(1, i, n, i) == n) {
            //  cout << "Found At " << "(" << 1 << ", " << i << ")" << " -> " << "(" << n << ", " << i << ")" << "\n";
            helper2(i, 1, n);
        }

    }    
    ans.push_back({ 0,0,0,0 });
    // cout << "Size : " << ans.size() << "\n";
    // for (auto& it : ans) {
    //    for (auto& it2 : it) {
    //        cout << it2 << " ";
    //  }cout << '\n';
    //}
    traffic_report(ans[0][0], ans[0][1], ans[0][2], ans[0][3], ans[1][0], ans[1][1], ans[1][2], ans[1][3]);
    return 0;
}