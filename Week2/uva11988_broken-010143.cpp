// ku01_next.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string input;
    list<char> ans;
    
    while (cin >> input) {
        ans.clear();
        auto it = ans.begin();
        for (auto c : input) {

            if (c == '[') {
                it = ans.begin();
            }
            else if (c == ']')
            {
                it = ans.end();
            }
            else {
                ans.insert(it, c);

            }
            
        }for (auto i : ans)
            cout << i;
        cout << "\n";
    }
    return 0;
}
