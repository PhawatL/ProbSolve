#include <bits/stdc++.h>
using namespace std;

long long n, m, y, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int j = 1; j < n + 1; j++)
    {
        cin >> x >> y;
        vector<long long> xi(x); // need
        vector<long long> yi(x); // can
        for (auto &it : xi)
            cin >> it;
        for (auto &it : yi)
            cin >> it;
        vector<long long> profit;
        for (long long i = 0; i < x; i++)
            profit.push_back(yi[i] - xi[i]);
        sort(profit.begin(), profit.end());
        long long sum = 0;
        for (auto it : profit)
        {
            if (it < 0 && y) y--;
            else sum += it;
        }
        if (sum <= 0)
            cout << "Case " << j << ": " << "No Profit" << "\n";
        else
            cout << "Case " << j << ": " << sum << "\n";
    }
    return 0;
}