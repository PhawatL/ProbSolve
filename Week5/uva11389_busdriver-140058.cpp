#include <bits/stdc++.h>
using namespace std;

int n, d, r, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        vector<int> morn, even;
        int paid = 0;
        cin >> n >> d >> r;

        if (!n)
            break;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            morn.push_back(x);
        }
        sort(morn.begin(), morn.end());
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            even.push_back(x);
        }
        sort(even.rbegin(), even.rend());


        for (int i = 0;i<n;i++){
            paid += max(0,((morn[i] + even[i]) - d)*r);
        }


        cout << paid << "\n";
    }

    return 0;
}