// #include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


void print_list(list<int> l) {
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}
unordered_map<int, list<int>> addr;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int loop, action;
    cin >> loop >> action;
    int limit;
    int i = 1;

    for (int k = 0; k < loop; k++)
    {
        cin >> limit;
        for (int j = i; j < limit + i; j++)
        {
            addr[i].push_back(j);
        }
        addr[addr[i].back()] = addr[i];
        i += limit;

    }

    char ac;
    int insert_at;
    auto it = addr[1].begin();
    
    for (int i = 0; i < action; i++)
    {


        cin >> ac;
        if (ac == 'F' && *it != addr[1].back()) {
            it++;
        }
        else if (ac == 'B' && *it != addr[1].front()) {
            it--;
        }
        else if (ac == 'C') {
            cin >> insert_at;
            if (addr[insert_at].empty())
                continue;

            auto tmp_list = addr[insert_at];
            if (tmp_list.front() != insert_at) {
                reverse(tmp_list.begin(), tmp_list.end());
            }

            list<int>res_list;
            auto cut = next(it);
            res_list.splice(res_list.begin(), addr[1], cut, addr[1].end());
            if (res_list.size()) {
                // cout << "res_list : ";
                // print_list(res_list);
                addr[res_list.front()] = res_list;
                addr[res_list.back()] = res_list;
            }

            addr[1].splice(addr[1].end(), tmp_list);



            it++;

        }
        // for (auto it2 : addr[1]) {
        //     cout << it2 << " ";
        // }
        // cout << "\niterator here : " << *it << "\n";
        ans.push_back(*it);
    }
    for (auto i : ans) cout << i << "\n";
    return 0;
}