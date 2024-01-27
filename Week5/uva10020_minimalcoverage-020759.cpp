#include <bits/stdc++.h>
using namespace std;

int n, m, y, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int j = 0; j < n; j++)
    {

        vector<vector<int>> v;
        cin >> m;
        cin >> x >> y;
        while (x || y)
        {

            if (y < 0 || x > m)
            {
                cin >> x >> y;
                continue;
            }
            v.push_back({x, y});
            cin >> x >> y;
        }
        sort(v.begin(), v.end());
        int curr_end = 0, max_end = 0;
        vector<vector<int>> ans;
        while (v.size() && curr_end < m)
        {

            vector<int> selected = v[0];

            for (auto &it : v)
            {
                if (it[0] <= curr_end)
                {
                    if (it[1] > max_end)
                    {
                        selected = it;
                        max_end = it[1];
                    }
                }
            }
            if (max_end == curr_end)
            {
                ans.clear();
                break;
            }
            ans.push_back(selected);
            curr_end = selected[1];
            max_end = selected[1];
        }
        cout << ans.size() << "\n";
        for (auto &it2 : ans)
            cout << it2[0] << " " << it2[1] << "\n";
        cout << "\n";
    }
    return 0;
}