// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include<vector>
#include<list>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    list<int> lst;
    int loop;
    char action;
    int input;
    cin >> loop;
    for (int i = 0; i < loop; i++) {
        cin >> action >> input;
        if (action == 'I') {
            lst.push_front(input);
        }else if (action == 'A'){
            lst.push_back(input);
        }
        else {
            auto it = lst.begin();
            for (int j = 0; j < input - 1 && it != lst.end(); j++) {

                it++;
            }
            if (it != lst.end())
                lst.erase(it);
        }

    }

    for (auto i : lst) {
        cout << i << "\n";
    }



    return 0;
}