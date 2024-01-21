#include <bits/stdc++.h>

using namespace std;

int endd = -1,num_f = 0;
int h, f,x,y;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> f;
    for (int i = 0; i < h; i++)
    {
        cin >> x >> y;
        if (y > endd){
            endd = x + f;
            num_f++;
        }   
    }
    cout << num_f << "\n";
    return 0;
}