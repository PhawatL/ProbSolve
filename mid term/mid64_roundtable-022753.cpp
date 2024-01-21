#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits> 
#include <cmath> 
#include <unordered_map> 
#include <map> 

using namespace std;

int main() {
    
    int loop, x,ans = 1;    
    cin >> loop;
    int mid = loop/2;
    map<int,int>v;
    vector<int>v1;
    for (int i = 1; i < loop+1; i++) {
        cin >> x;
        int loc = x - i;
        if (loc < 0) loc = loop + loc;
        v[loc]++;
        
    }
    int m=0;
    for (auto& it : v) {
        // cout << "Key :" << it.first << " : " << it.second << "\n";
        ans = max(it.second,ans);
        
    }

    cout << ans;
    return 0;
}
