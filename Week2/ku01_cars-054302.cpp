#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int loop;
    cin >> loop;
    int p, v;
    vector<int> value;
    for (int i = 0; i < loop; i++) {
        cin >> p >> v;
        value.push_back(v);
    }
    int comp = value.back();
    int t = 0;
    for (int i = value.size() - 2; i > -1;i--) {
        if (value[i] <= comp) {
            t++;
        }
        else {
            comp = value[i];
        }
    }
    cout << t;
    return 0;
}