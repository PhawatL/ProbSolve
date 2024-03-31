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

int main()
{
    long long l, x,y,z;
    cin >> l;
    vector<vector<long long>>v;
    vector<long long>dp(l+10,0);
    
    for (int i = 0; i < l; i++) {
        cin >> x >> y >> z;
        v.push_back({ x,y,z });
    }
    for (int i = l - 1; i >= 0; i--) {

        long long temp = v[i][0] + dp[i + 1];
        temp = max<long long int>(temp,v[i][1] + dp[i + 2]);
        temp = max<long long int>(temp, v[i][2] + dp[i + 4]);
        dp[i] = temp;
    }
    cout << dp[0] << "\n";
    
    return 0;
}