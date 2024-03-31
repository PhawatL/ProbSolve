#include <bits/stdc++.h>
using namespace std;


vector<vector<vector<int>>> dp;

int bruteforce(string &s, int pos1, int pos2, size_t index)
{

    if (dp[pos1][pos2][index] != -1)
        return dp[pos1][pos2][index];

    if (index == s.size())
        return 0;


    int rotate1 = abs((int)s[index] - 64 - pos1);
    if (rotate1 > 12)
        rotate1 = 26 - rotate1;
    int ans1 = bruteforce(s, (int)s[index] - 64, pos2, index + 1) + rotate1;


    int rotate2 = abs((int)s[index] - 64 - pos2);
    if (rotate2 > 12)
        rotate2 = 26 - rotate2;
    int ans2 = rotate2 + bruteforce(s, pos1, (int)s[index] - 64, index + 1);


    int ans = min(ans1, ans2);


    dp[pos1][pos2][index] = ans;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        dp.assign(27, vector<vector<int>>(27, vector<int>(1001, -1)));
        cout << bruteforce(s, 1, 1, 0) << "\n";
    }

    return 0;
}