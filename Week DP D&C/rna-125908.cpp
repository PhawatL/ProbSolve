#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

string s;
vector<vector<int>> dp;
class Solution{ 
public:
    int solve(string& s,int start, int end) {
        if (start >= end - 4) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int result = 0;
        for (int i = start; i <= end; i++) {
            for (int j = i + 4; j <= end; j++) {
                
                if (((s[i] == 'A' && s[j] == 'U') || (s[i] == 'U' && s[j] == 'A')) || ((s[i] == 'C' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'C'))) {
                    result = max(result,1 + solve(s,start,i-1) + solve(s,i+1,j-1) + solve(s,j+1,end)); 
                }
            }
        }
        dp[start][end] = result; 
        return result;
    }
};

int main(){
    string s;
    int n;
    cin >> s;
    n = s.size();
    dp.assign(n,vector<int>(n,-1));
    Solution sol;
    cout << sol.solve(s,0,n-1);
    return 0;
}