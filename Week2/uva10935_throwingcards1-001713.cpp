// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, tmp;
    queue<int> q;
    cin >> n;
    while (n) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        cout << "Discarded cards:";
        while (q.size() > 1) {
            cout << ' ' << q.front();
            q.pop();
            tmp = q.front();
            q.pop();
            if (!q.empty())
                cout << ',';
            q.push(tmp);
        }
        cout << '\n' << "Remaining card: " << q.front() << '\n';
        q.pop();
        cin >> n;

    }

    return 0;
}
