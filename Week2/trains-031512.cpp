// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <map>
#include<vector>
#include<list>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, list<int>> m;
    int loop, i, j;
    char action;
    cin >> loop;
    for (int l = 0; l < loop; l++) {
        cin >> action >> i >> j;
        if (action == 'N') {
            m[j].push_back(i);
        }
        else {
            m[j].splice(m[j].end(), m[i]);
 
            m[i].clear();
        }


    }
    for (auto& a : m) {
        for (auto b : a.second) {
            cout << b << "\n";
        }
    }
    cout << "\n";



    return 0;
}