#include <bits/stdc++.h>
using namespace std;

int n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n && n)
    {
        vector<int> bucket(100, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            bucket[x - 1]++;
        }
        string sep = "";
        for (int i = 0; i < 100; i++)
        {

            for (int j = 0; j < bucket[i]; j++)
            {
                cout << sep << i + 1;
                sep = " ";
            }
        }
        cout << "\n";
    }

    return 0;
}