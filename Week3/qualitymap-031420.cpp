#include <bits/stdc++.h>

using namespace std;


int n,m;
vector<string>v;


unordered_map<int,pair<int,int>> state;

void printVisited(const vector<vector<bool>>& visited) {
    cout << "\nVisited\n";
    for (int i = 0;i<visited.size();i++) {
        for (int j = 0;j<visited[0].size();j++) {
            if (v[i][j] == '#') cout << "# ";
            else cout << visited[i][j] << " ";
        }
        cout << "\n";
    }cout << "\n";
}

bool is_valid_point(int x,int y, vector<vector<bool>>& visited){
    
    if (x < 0 || y < 0) return false;
    if (x >= n || y >= m) return false;
    if (v[x][y] == '#') return false;
    if (visited[x][y]) return false;

    return true;
}

void expand_map(int x,int y,int cls, vector<vector<bool>>& visited){
    if (!is_valid_point(x,y,visited)) return;
    // cout << "Visit at " << x << " " << y ;
    visited[x][y] = true;
    // printVisited(visited);
    state[cls].first++;
    if (v[x][y] == '*'){
        if (state[cls].second == 0){
            state[cls].second = 1;
        }else if (state[cls].second == 2){
            state[cls].second = 3;
        }
    }else if (v[x][y] == '$'){
        if (state[cls].second == 0){
            state[cls].second = 2;
        }else if (state[cls].second == 1){
            state[cls].second = 3;
        }
    }
    expand_map(x+1,y,cls,visited);
    expand_map(x,y+1,cls,visited);
    expand_map(x-1,y,cls,visited);
    expand_map(x,y-1,cls,visited);

}

int main() {

    int value1 = 0,value2 = 0;
    string tmp;
    cin >> n >> m;
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    int cls = 1;
    for (int i = 0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    // cout << "\n";
    // printVisited(visited);
    for (int row = 0;row<n;row++){

        for (int column = 0 ;column<m;column++){
            if ('#' == v[row][column] || visited[row][column] ) continue;
            // cout << v[row][column];
            state[cls] = make_pair(0,0);
            // cout << "   class : " << cls << "\n\n";
            expand_map(row,column,cls,visited);
            
            if (state[cls].second == 3){
                value2 += state[cls].first;
            }else if (state[cls].second == 1){
                value1 += state[cls].first;
            }else if (state[cls].second == 2){
                value1 += state[cls].first;
            }
            cls++;
            

        }// cout << "\n";

    }// cout << "\n";
    // for (const auto& entry : state) {
    //     std::cout << "Key: " << entry.first << " - Value: (" << entry.second.first << ", " << entry.second.second << ")\n";
    // }
    cout << value2 << " " << value1 << "\n";



    return 0;
}
