#include <bits/stdc++.h>
using namespace std;

int start, stop;

bool check_prime(int num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int ans = 0;
queue<int> q;
int main()
{

    cin >> start >> stop;
    if (stop < 5)
    {
        cout << 0;
        return 0;
    }
    for (int i = start; i <= stop; i++)
    {
        if (i % 2 == 0)
            continue;

        if (check_prime(i))
        {
            q.push(i);
            if (q.size() == 2)
            {
                if (q.back() - q.front() == 2)
                    ans++;
                q.pop();
            }
        }
    }
    cout << ans;
    return 0;
}