#include <bits/stdc++.h>
using namespace std;

long long glob = 0;

vector<int> inversion_count(vector<int> &v)
{

    if (v.size() <= 1)
        return v;
    int mid = v.size() / 2;

    vector<int> l;
    vector<int> r;

    for (int i = 0; i < mid; i++)
        l.push_back(v[i]);
    for (int i = mid; i < v.size(); i++)
        r.push_back(v[i]);
    l = inversion_count(l);
    r = inversion_count(r);

    int l_p = l.size() - 1;
    int r_p = r.size() - 1;

    while (l_p >= 0 && r_p >= 0)
    {

        if (l[l_p] > r[r_p])
        {
            glob += r_p + 1;
            l_p -= 1;
        }
        else
            r_p -= 1;
    }

    vector<int> tmp;
    int i = 0, j = 0;
    while (1)
    {

        if (i == l.size())
        {
            for (int k = j; k < r.size(); k++)
                tmp.push_back(r[k]);
            break;
        }
        if (j == r.size())
        {
            for (int k = i; k < l.size(); k++)
                tmp.push_back(l[k]);
            break;
        }

        if (l[i] <= r[j])
        {
            tmp.push_back(l[i++]);
        }
        else
        {
            tmp.push_back(r[j++]);
        }
    }
    return tmp;
}

int n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    inversion_count(v);
    cout << glob;
    return 0;
}