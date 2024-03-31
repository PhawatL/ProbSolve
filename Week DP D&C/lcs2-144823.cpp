#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

class Solution {
public:
    void longestCommonSubsequence(string& text1, string& text2) {
        int text1Length = text1.size(), text2Length = text2.size();
        
        int dp[text1Length + 1][text2Length + 1];
        vector<vector<pair<int,int>>> pointer(text1Length + 1, vector<pair<int,int>>(text2Length + 1, pair<int,int>{-1,-1}));
        memset(dp, 0, sizeof dp);

        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]){
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    pointer[i][j] = {i+1,j+1};
                }else{
                    if (dp[i][j + 1] > dp[i + 1][j]){
                        dp[i][j] = dp[i][j + 1];
                        pointer[i][j] = {i,j+1};
                    }else{
                        dp[i][j] = dp[i + 1][j];
                        pointer[i][j] = {i+1,j};
                    }
                }
            }
        }
        cout << dp[0][0] << "\n";
        int i = 0,j = 0;
        while (pointer[i][j].first != -1){
            int ii = pointer[i][j].first;    
            int jj = pointer[i][j].second;    
            if (ii == i + 1 && jj == j + 1)
                cout << text1[i];        
            i = ii;
            j = jj;
        }
        cout << "\n";

        
    }
};
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    Solution sol;
    sol.longestCommonSubsequence(s1,s2);
    return 0;
}