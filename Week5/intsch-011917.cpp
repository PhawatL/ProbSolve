#include <bits/stdc++.h>
using namespace std;

int l,x,y;

vector<pair<int,int>>v;
int main()
{
    cin >> l;
    for (int i =0;i<l;i++){

        cin >> x >> y;
        v.push_back({y,x});
    }
    
    sort(v.begin(),v.end());
    int f = -1,counter = 0;
    for (auto it:v){

        if (it.second >= f){
            counter++;
            f = it.first;
        }
    
    }
    cout << counter ;
    return 0;
}