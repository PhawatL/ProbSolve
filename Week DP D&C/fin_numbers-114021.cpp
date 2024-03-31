#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, z;

void func(vector<pair<int, int>> v)
{

    int stand = v.size() - 1;
    
    while (stand--)
    {
        int tmp_cost = INT_MIN;
        for (int i = 1; i < 5; i++)
        {
            
            if (stand + i >= (int)v.size())
            {
                tmp_cost = max(tmp_cost,0);
                break;
            }
            tmp_cost = max(tmp_cost, v[stand + i].first);
            if (v[stand + i].second)
            {
                break;
            }
            // cout << "stand : " << stand << " i = " << i  <<  " tmp_cost : " << tmp_cost << "\n";

        }
        v[stand].first += tmp_cost;
    }

    // for (auto it : v)
    //     cout << it.first << " ";
    // cout << "\n";
    int m = INT_MIN;
    for (int i = 0; i < 4; i++)
    {

        m = max(m, v[i].first);
        if (v[i].second)
        {
            if (m > v[i].first)
                break;
            m = v[i].first;
            break;
        }
    }
    cout << m;
}

int main()
{
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {

        cin >> x;
        v.push_back({x, 0});
    }

    for (int i = 0; i < n; i++)
    {

        cin >> x;
        v[i].second = x;
    }
    func(v);
    return 0;
}