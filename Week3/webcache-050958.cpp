// #include <bits/stdc++.h>
 #include <iostream>
 #include <list>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>
 #include <queue>
using namespace std;


void print_list(list<int> l) {
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}


int req,ans = 0;

unordered_map<int,int>m;
queue<int>q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,mm;
    cin >> n >> mm;

    for (int i=0;i<mm;i++){
        cin >> req;
        
        if (!m[req]){   
            ans++;
            m[req]++;
            if (q.size() == n){
                m[q.front()] = 0;
                q.pop();
            }
            q.push(req);
        }
        
        //for (auto it : m) {
        //    cout << it.first << " : " << it.second << "\n";
        //}

    }cout << ans << "\n";

    return 0;
}