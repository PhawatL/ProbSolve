#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> v;
int x, y, min_num = INT_MAX;

int main()
{

    // ofstream outputFile("output.txt");

    // // Check if the file is successfully opened
    // if (!outputFile.is_open()) {
    //     cerr << "Error opening the file!" << endl;
    //     return 1; // Return an error code
    // }

    // // Redirect cout to the file
    // streambuf *original_cout = cout.rdbuf();
    // cout.rdbuf(outputFile.rdbuf());



    cin >> n >> q;
    vector<int> inv_v(n);
    for (int i = 0; i < n; i++)
    {

        cin >> x;
        min_num = min(min_num, x);
        v.push_back(min_num);
        inv_v[n - i - 1] = min_num;
    }
    // cout << "Vector : \n";
    // for (auto it : v)
    //     cout << it << " ";
    // cout << "\n";
    for (int i = 0; i < q; i++)
    {

        cin >> x >> y;
        if (x == 1)
        {
            cout << v[y - 1] << "\n";
        }
        else
        {
            auto upper = upper_bound(inv_v.begin(), inv_v.end(), y);
            auto lower = lower_bound(inv_v.begin(), inv_v.end(), y);
            int u,l;
            if (upper != inv_v.end())
            {
                
                u =  n - 1 - (upper - inv_v.begin()) ;
            }
            else
            {
                u = -1;
            }
            if (lower != inv_v.end())
            {
                
                l =  n - 1 - (lower - inv_v.begin());
            }
            else
            {
                l = -1;
            }
            // cout << "upper : " << u << " lower : " << l << "\n";
            int tmp = max(u,l);
            cout << tmp + 1 << "\n";
        }
    }
    // cout.rdbuf(original_cout);
    return 0;
}