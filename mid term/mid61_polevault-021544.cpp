#include <bits/stdc++.h>
using namespace std;

int n, q, x;
vector<int> p;
unordered_set<int> poss;
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    
    for (int i=0;i<n;i++){
        int counter = 0;
        for (int j=i;j<n;j++){
            counter += p[j];
            poss.insert(counter);
        }
    }
    for (int i =0;i<q;i++){
        cin >> x;
        if (poss.find(x) != poss.end()){
            cout << "Y";
        }else{
            cout << "N";
        }
    }
    return 0;
}