#include <bits/stdc++.h>
using namespace std;

double n, r, y, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int j = 1;
    while (cin >> n >> r && n && r)
    {
        vector<pair<double, double>> v;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (abs(y) > r)
                flag = true;
            v.push_back({x + sqrt(r * r - y * y), x - sqrt(r * r - y * y)});
        }
        if (flag)
        {
            cout << "Case " << j++ << ": " << -1 << "\n";
            continue;
        }
        sort(v.begin(), v.end());
        double end = v[0].first, counter = 1;
        for (auto it : v)
        {
            if (it.second > end)
            {
                end = it.first;
                counter++;
            }
        }
        cout << "Case " << j++ << ": " << counter << "\n";
    }

    return 0;
}
