 #include <bits/stdc++.h>
//  #include <iostream>
//  #include <list>
//  #include <vector>
//  #include <unordered_map>
//  #include <algorithm>
//  #include <queue>
using namespace std;


int req,ans = 0;
set<vector<int>>s;
unordered_map<int,vector<int>>map_key;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int loop,x,y;
    cin >> loop;
    for (int i = 0; i < loop; i++) {
        cin >> x >> y;
        if (x){
            if (map_key.count(y) == 0){
                vector<int>v_tmp{-1,-i,y};
                map_key[y] = v_tmp;
                s.insert(v_tmp);
            }else{
                auto v_tmp = map_key[y];
                s.erase(v_tmp);
                v_tmp[0]--;
                v_tmp[1] = -i;
                s.insert(v_tmp);
                map_key[y] = v_tmp;

            }
            
        }else{
            // cout << "Unlike Time\n";
            auto v_tmp = map_key[y];
            s.erase(v_tmp);
            v_tmp[0]++;
            v_tmp[1] = -i;
            s.insert(v_tmp);
            map_key[y] = v_tmp;

        }
        auto first = s.begin();
        cout << (*first)[2] << "\n";
        // for (auto& it:s){
        //     for (auto it2:it){
        //         cout << it2 << " ";
        //     }cout << ", ";
        // }cout << "\n";

    }

    

    return 0;
}