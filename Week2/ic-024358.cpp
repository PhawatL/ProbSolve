// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <sstream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    list<int> q;
    int loop;
    cin >> loop;

    string action;
    int input;
    for (int i = 0; i < loop; i++) {
        cin >> action;

            if (action == "ri") {
                cin >> input;
                q.push_back(input);
            }

            else if (action == "li") {
                cin >> input;
                q.push_front(input);
            }

            else if (action == "lr") {
                q.push_back(q.front());
                q.pop_front();
            }
            else if (action == "rr") {
                q.push_front(q.back());
                q.pop_back();
            }
  
        

    }
    for (auto i : q) {

        cout << i << "\n";

    }



    return 0;
}