#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main()
{

    int n, m, x, y;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        l.push_back(x);
    }
    auto it = l.begin();
    for (int i = 0; i < m; i++)
    {

        cin >> x;
        switch (x)
        {
        case 1:
            it = l.begin();
            break;
        case 2:
            if (l.back() == *it)
            {
                it = l.begin();
                break;
            }
            it++;
            break;
        case 3:
            cin >> y;
            l.insert(it, y);
            break;
        case 4:
            cin >> y;
            it++;
            l.insert(it, y);
            it--;
            it--;
            break;
        default:
            break;
        }

    //     for (auto j : l)
    //     {
    //         if (j == *it)
    //         {
    //             cout << "(" << *it << ") ";
    //             continue;
    //         }
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    }
    for (auto j : l)
    {

        cout << j << "\n";
    }

    return 0;
}