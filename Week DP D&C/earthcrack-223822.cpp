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
using namespace std;

int num_test,m,n,x;

bool is_valid(int x, int y, vector<vector<int>>& visited) {

    int n = visited.size(), m = visited[0].size();

    if (x >= n || y >= m) return false;
    if (x < 0 || y < 0) return false;

    return true;
}

int traverse(vector<vector<int>>& earth, vector<vector<int>>& visited,int x,int y) {

    if (visited[x][y] != -1) return visited[x][y];

    int w = earth[x][y];
    int m = INT_MAX;
    
    if (is_valid(x + 1, y, visited)) {
        m = min(m,traverse(earth, visited, x + 1, y));
    }
    if (is_valid(x + 1, y+1, visited)) {
        m = min(m, traverse(earth, visited, x + 1, y + 1));
    }
    if (is_valid(x + 1, y-1, visited)) {
        m = min(m, traverse(earth, visited, x + 1, y - 1));
    }

    if (m == INT_MAX)
        m = 0;
    visited[x][y] = earth[x][y] + m;

    return visited[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num_test;
    while (num_test--) {
        cin >> n >>  m;
        vector<vector<int>>earth;
        for (int i = 0; i < n; i++) {
            vector<int>temp_vec;
            for (int j = 0; j < m; j++) {
                cin >> x;
                temp_vec.push_back(x);
            }
            earth.push_back(temp_vec);
        }
        vector<vector<int>> visited(n, vector<int>(m, -1));
        for (int k = 0;k<m;k++)
            traverse(earth, visited, 0, k);
        int ans = INT_MAX;
        for (auto& it : visited[0])
            ans = min(ans, it);
        cout << ans << "\n";

    }
    return 0;
}