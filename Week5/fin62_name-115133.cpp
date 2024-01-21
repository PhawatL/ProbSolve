#include <bits/stdc++.h>

using namespace std;

string name,text;
int counter = 0,runner = 0;


int main()
{
    cin >> name >> text;
    
    for (auto c:text){
        if (name[runner] == c)
            runner++;
        
        if (runner == name.size()){
            runner = 0;
            counter++;
        }
    }
    cout << counter << "\n";


    return 0;
}