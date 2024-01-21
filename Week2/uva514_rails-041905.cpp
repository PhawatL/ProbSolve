#include <iostream>
#include <stack>
using namespace std;

bool helper(int n, int target[]) {
    int cc = 1, tar = 0;
    stack<int> station;

    while (cc <= n) {
        station.push(cc);

        while (!station.empty() && station.top() == target[tar]) {
            station.pop();
            tar++;
            if (tar >= n)
                break;
        }

        cc++;
    }

    return station.empty();
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        while (true){
            int tar[1000];
            for (int i = 0; i < n; i++) {
                cin >> tar[i];
                if (tar[0] == 0) break;
            }
            if (tar[0] == 0) break;
            if (helper(n, tar)) {
                cout << "Yes" << "\n";
            }
            else {
                cout << "No" << "\n";
            }
        }

        cout << "\n";
    }

    return 0;
}