#include <bits/stdc++.h>
using namespace std;

int loop, x, init;

map<int, int> counter;
deque<vector<int>> v{{0, 0}};
int main()
{

    cin >> loop;
    for (int i = 1; i <= loop; i++)
    {
        cin >> x;
        while (x < v[0][0])
        {

            int length = i - v[0][1];
            int num;
            if (x > v[1][0])
            {
                num = v[0][0] - x;
                init = v[0][1];
                v.pop_front();
                v.push_front({x, init});
            }
            else
            {
                num = v[0][0] - v[1][0];
                v.pop_front();
            }
            counter[length] += num;
        }
        if (v[0][0] != x)
        {
            v.push_front({x, i});
        }

        if (v[0][0] == 0)
        {
            v.pop_front();
            v.push_front({x, i});
        }

    }

    int x = 0;
    int i = loop + 1;
    while (x < v[0][0])
    {

        int length = i - v[0][1];
        int num;
        if (x > v[1][0])
        {
            num = v[0][0] - x;
            init = v[0][1];
            v.pop_front();
            v.push_front({x, init});
        }
        else
        {
            num = v[0][0] - v[1][0];
            v.pop_front();
        }

        counter[length] += num;

    }
    cout << counter.size() << "\n";
    for (auto &it : counter)
        cout << it.first << " " << it.second << "\n";

    return 0;
}