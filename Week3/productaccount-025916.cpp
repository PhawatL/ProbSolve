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

    int loop,action,x,y;
    cin >> loop;
    for (int i = 0; i < loop; i++) {
        cin >> action;
        
        switch (action) {

        case 1:
            cin >> x >> y;
            m[x] += y;
            break;

        case 2:
            cin >> x;
            cout << m[x] << "\n";
            break;

        case 3:
            cin >> x >> y;

            cout << min(m[x], y) << "\n";
            m[x] = max(0, m[x] - y);
            break;
        }



    }

    return 0;
}
