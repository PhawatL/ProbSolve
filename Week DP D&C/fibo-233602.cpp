#include <bits/stdc++.h>
using namespace std;

int n, x;
int main()
{
    cin >> n;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        int temp = b;
        b = (a + b) % 199933;
        a = temp ;}
    cout << a;
    return 0;
}