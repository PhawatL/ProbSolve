// #include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

void print_list(list<int> l) {
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}

void print_vector(vector<int> l) {
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, tmp;
    cin >> n >> k;

    set<int> s;
    int b = 0;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(tmp);
    }

    vector<int> input;
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        input.push_back(tmp);
    }
    int ans;
    for (auto it : input) {
        int min_diff = 2000000000;
        
        auto u = s.upper_bound(it);
        if (u == s.end())
            u--;
        if (abs(*u - it) < min_diff) {
            min_diff = abs(*u - it);
            ans = *u;
        }
        auto l = s.lower_bound(it);
        if (l == s.end())
            l--;

        if (abs(*l - it) <= min_diff) {
            min_diff = abs(*l - it);
            ans = *l;
        }
        l--;
        if (abs(*l - it) <= min_diff) {
            min_diff = abs(*l - it);
            ans = *l;
        }

        cout << ans << "\n";
    }

    return 0;
}
