#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a;
    cin>>n;
    vector<int> v(n+5);
    vector<int> ans(n+5);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    ans[1]=0;
    ans[2]=0;
    ans[3]=v[3];
    for(int i=3;i<ans.size();i++){
        if(i-3<0){
            continue;
        }
        ans[i]=max(ans[i-1],max(ans[i],ans[i-3]+v[i]));
    }
    cout<<ans[n+1];
}