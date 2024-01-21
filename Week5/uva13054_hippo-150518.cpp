#include <bits/stdc++.h>
using namespace std;

int n, h, ta, td, x;

int main()
{
    int loop;
    cin >> loop;
    for (int l = 1; l < loop + 1; l++)
    {
        vector<int> v;

        int paid = 0;
        cin >> n >> h >> ta >> td;

        if (!n)
            break;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        if (td >= 2 * ta)
        {
            cout << "Case " << l << ": " << ta * n << "\n";
            continue;
        }

        sort(v.begin(), v.end());
        int start = 0, end = n - 1;

        while (start < end){

            if (h > (v[start] + v[end])){
                start++;
                end--;
                paid+=td;
            }else{
                end--;
                paid+=ta;

            }

        }
        if (start == end) paid += ta;
        cout << "Case " << l << ": " << paid << "\n";
    }
    return 0;
}