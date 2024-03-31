#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, z, ma;

int main()
{

    cin >> n;
    vector<int> index(n, 1);
    vector<int> pointer(n, 0);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        int tmp_max = 0, idx = i;
        for (int j = i - 1; j > -1; j--)
        {
            if (v[j] < v[i] && tmp_max < index[j])
            {
                tmp_max = index[j];
                idx = j;
            }
        }
        index[i] += tmp_max;
        pointer[i] = idx;
    }
    int g_max = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (g_max < index[i])
        {
            g_max = index[i];
            idx = i;
        }
    }
    // for (auto it : index)
    //     cout << it << " ";
    // cout << "\n";
    // for (auto it : pointer)
    //     cout << it << " ";
    // cout << "\n";    
    deque<int> t;
    while (idx != pointer[idx])
    {
        t.push_front(v[idx]);
        idx = pointer[idx];
    }
    t.push_front(v[idx]);
    cout << t.size() << "\n";
    for (auto it : t)
        cout << it << " ";
    cout << "\n";
    return 0;
}