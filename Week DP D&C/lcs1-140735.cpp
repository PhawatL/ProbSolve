#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int text1Length = text1.size(), text2Length = text2.size();
        
        int dp[text1Length + 1][text2Length + 1];
      
        memset(dp, 0, sizeof dp);

        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }
};

int main() {

    string s1,s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.longestCommonSubsequence(s1,s2);

    return 0;
}
