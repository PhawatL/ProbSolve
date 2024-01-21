#include <bits/stdc++.h>
using namespace std;


int loop,x,y;
vector<int> v(21,0);
int main()
{
    cin >> loop;
    int x,y,z;
    for (int i=0;i<loop;i++){

        for (int k=1;k<21;k++){
            v[k-1]+=v[k];
            v[k] = 0;
        }

        cin >> x;
        for (int j=0;j<x;j++){

            cin >> y >> z;
            v[z] += y;
        }

        int counter = -v[0];
        for (auto it:v) counter+=it;
        cout << counter << "\n";

    }
    


    return 0;
}