#include <bits/stdc++.h>
using namespace std;

int n, m, y, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int j = 1; j < n + 1; j++)
    {
        cin >> m;
        string field;
        cin >> field;
        int i = -1, cum_f = 0, sc = 0;
        while (i++ < m)
        {
            if (field[i] == '.')
            {
                cum_f++;
            }
            else
            {
                if (cum_f == 1)
                {
                    sc++;
                    i++;
                    cum_f = 0;
                }
            }
            if (cum_f == 2)
            {
                sc++;
                i++;
                cum_f = 0;
            }
        }
        if (cum_f)
            sc++;
        cout << "Case " << j << ": " << sc << "\n";
    }
    return 0;
}
