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
unordered_map<int, int>m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int loop,tmp,max_prev = 0;
    cin >> loop;
    for (int i = 0; i < loop; i++) {
        cin >> tmp;
        m[tmp]++;
        if (m[max_prev] <= m[tmp]) {
            max_prev = tmp;
        }cout << max_prev << "\n";
    }

    return 0;
}
