#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int curr_min = min(v[0], v[1]);
    int curr_max = max(v[0], v[1]);
    vector<int> dp{0, curr_max - curr_min};
    if (n == 2)
    {
        cout << dp[1];
        return 0;
    }
    curr_max = max(curr_max, v[2]);
    curr_min = min(curr_min, v[2]);

    dp.push_back(curr_max - curr_min);
    for (int i = 3; i < n; i++)
    {
        int curr_min = min(v[i], v[i - 1]);
        int curr_max = max(v[i], v[i - 1]);
        int target_value = curr_max - curr_min + dp[i - 2];
        for (int j = i - 2; j >= 0; j--)
        {
            if (i - j > 9)
                break;
            curr_max = max(curr_max, v[j]);
            curr_min = min(curr_min, v[j]);
            if (j == 1)
                continue;
            // cout << i << " " << j << " :    " << curr_max << " " << curr_min << "\n";
            if (j == 0)
                target_value = min(target_value, curr_max - curr_min);
            else
                target_value = min(target_value, curr_max - curr_min + dp[j - 1]);
        }
        dp.push_back(target_value);
    }

    // for (auto it : dp)
    //     cout << it << " ";
    // cout << '\n';
    cout << dp[n - 1];

    return 0;
}