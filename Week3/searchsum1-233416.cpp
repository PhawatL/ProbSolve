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

void print_vector(vector<int> l) {
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}

int binary_search(vector<int>&v, int target) {
    int pointer = (v.size() - 1) / 2;

    //cout << pointer << " : " << v[pointer] << "\n";
    int upper = v.size()-1;
    int lower = 0;
    while (upper > lower) {
        if (v[pointer] > target) {

            upper = pointer - 1;
            pointer = (upper + lower) / 2;
        }
        else if (v[pointer] < target){

            lower = pointer + 1;
            pointer = (upper + lower) / 2;

        }
        else {
            return pointer;
        }
        //cout << "upper " << upper << " lower " << lower << "\n";
        //cout << pointer << " : " << v[pointer] << "\n";
        // sleep(0.1);

    }
    //cout << "END Search\n";
    return pointer;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k,tmp;
    cin >> n >> k;
    vector<int> v;
    int b = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp+b);
        b = v.back();
    }
    //print_vector(v);
    vector<int> cash;
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        cash.push_back(tmp);
        
        // cout << "ANS : " << v[binary_search(v, tmp)] << "\n";
    }

    for (auto c : cash) {
        int j = binary_search(v, c);
        for (; j < v.size(); j++) {

            if (v[j] > c) {
                break;
            }
        }
        cout << j << "\n";

    }


    return 0;
}