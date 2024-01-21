#include <bits/stdc++.h>
using namespace std;

int l,x,y;

vector<pair<int,int>>v;
int main()
{
    cin >> l;
    for (int i =0;i<l;i++){

        cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(),v.end());
    int time = 0,penalty = 0,m = 0;

    for (auto it:v){

        time += it.second;
        m = max(m,max(0,time-it.first-10) * 1000);

    }
    cout << m ;

    return 0;
}