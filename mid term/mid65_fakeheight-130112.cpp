#include <bits/stdc++.h>
using namespace std;

long long l, x;
vector<long long> v;
set<long long> s;
long long dis = 0;
int main()
{
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> x;
        v.push_back(x);
        s.insert(x);
        if (i)
        {
            dis += abs(v[i] - v[i - 1]);
        }
    }
    // cout << "dis = " << dis << "\n";
    long long max_imp = 0;
    for (int i = 1; i < l - 1; i++)
    {

        // interval
        if (((v[i] - v[i - 1]) ^ (v[i] - v[i + 1])) >= 0)
        {

            if (v[i - 1] < v[i + 1])
            {

                auto tmp = s.find(v[i - 1]);
                if (*next(tmp) != v[i + 1])
                { // ถ้าไม่เท่ากันแสดงว่ามีตัวเลขในช่วงที่ใช้ได้ ระยะที่เกิดขึ้นจะเหลือแค่ระยะห่างระหว่างช่วง

                    long long imp = abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]) - abs(v[i + 1] - v[i - 1]);
                    // cout << "imp = : " << imp << " v[i] = " << v[i] << "\n";
                    max_imp = min(max_imp, -imp);
                }
                else
                { // ถ้าเท่ากันแสดงว่าไม่มีตัวเลขมีช่วงที่ใช้ได้ ใช้ตัวเลขที่ใกล้ที่สุดของขอบมาคิดแทน
                    long long pre_value = 0;
                    long long post_value = 0;
                    if (tmp != s.begin())
                    {
                        tmp--;
                        pre_value = *tmp;
                        tmp++;
                    }

                    if (next(tmp, 2) != s.end())
                    {
                        post_value = *(next(tmp, 2));
                    }

                    long long tmp = min(abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]), abs(pre_value - v[i - 1]) + abs(pre_value - v[i + 1])) - (abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]));
                    if (pre_value)
                    max_imp = min(max_imp, tmp);
                    // cout << "imp = " << -tmp << "\n";
                    tmp = min(abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]), abs(post_value - v[i - 1]) + abs(post_value - v[i + 1])) - (abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]));
                    if (post_value)
                    max_imp = min(max_imp, tmp);
                    // cout << "imp = " << -tmp << "\n";
                }
            }
            else
            {
                auto tmp = s.find(v[i + 1]);
                if (*next(tmp) != v[i - 1])
                { // ถ้าไม่เท่ากันแสดงว่ามีตัวเลขในช่วงที่ใช้ได้ ระยะที่เกิดขึ้นจะเหลือแค่ระยะห่างระหว่างช่วง
                    // cout << *next(tmp) << " != " << v[i - 1] << "\n";
                    long long imp = abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]) - abs(v[i + 1] - v[i - 1]);
                    max_imp = min(max_imp, -imp);
                    // cout << "imp = : " << imp << " v[i] = " << v[i] << "\n";
                }
                else
                { // ถ้าเท่ากันแสดงว่าไม่มีตัวเลขมีช่วงที่ใช้ได้ ใช้ตัวเลขที่ใกล้ที่สุดของขอบมาคิดแทน
                    long long pre_value = 0 ;
                    long long post_value = 0;
                    if (tmp != s.begin())
                    {
                        tmp--;
                        pre_value = *tmp;
                        tmp++;
                    }

                    if (next(tmp, 2) != s.end())
                    {
                        post_value = *(next(tmp, 2));
                    }

                    long long tmp = min(abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]), abs(pre_value - v[i - 1]) + abs(pre_value - v[i + 1])) - (abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]));
                    if (pre_value)
                    max_imp = min(max_imp, tmp);
                    // cout << "imp = " << -tmp << "\n";
                    tmp = min(abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]), abs(post_value - v[i - 1]) + abs(post_value - v[i + 1])) - (abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]));
                    if (post_value)
                    max_imp = min(max_imp, tmp);
                    // cout << "imp = " << -tmp << "\n";
                }
            }
        }
    }

    // front
    for (int i = 2; i < l; i++)
    {

        long long tmp = min(abs(v[i] - v[1]), abs(v[1] - v[0])) - abs(v[1] - v[0]);
        max_imp = min(max_imp, tmp);
    }

    // tail
    for (int i = 0; i < l - 2; i++)
    {

        long long tmp = min(abs(v[i] - v[l - 2]), abs(v[l - 2] - v[l - 1])) - abs(v[l - 2] - v[l - 1]);
        max_imp = min(max_imp, tmp);
    }
    // cout << max_imp << "\n";

    cout << dis + max_imp << "\n";
    return 0;
}
