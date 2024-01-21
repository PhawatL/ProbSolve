#include <bits/stdc++.h>

using namespace std;

string name,text;
int num_contract,num_cargo;
vector<vector<int>> contract;
int x,y,z;
vector<int>cargoes;
int min_paid = 2000000000;
int main()
{
    cin >> num_contract >> num_cargo;

    for (int i = 0;i<num_contract;i++){
        cin >> x >> y >> z;
        contract.push_back({x,y,z});
    }

    for (int i = 0;i<num_cargo;i++){
        cin >> x;
        cargoes.push_back(x);
    }

    for (auto con:contract){
        int w = con[2];
        int num_truck = 1;
        int curr_f = 0;
        int it = 0;
        bool flag = false;
        while (it < num_cargo){
            int cargo = cargoes[it];
            if (cargo > w){
                flag = true;
                break;
            }
            if (curr_f + cargo <= w){
                curr_f += cargo;
                it++;
            }else{
                curr_f = 0;
                num_truck++;
            }
        }
        if (flag) continue;
        min_paid = min(min_paid,con[0] + num_truck * con[1]);

    }
    cout << min_paid << "\n";
    return 0;
}