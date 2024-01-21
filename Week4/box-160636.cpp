#include <bits/stdc++.h>
using namespace std;

    
int n,m;
string input;
vector<string>maze;


bool valid_point(int x,int y,vector<vector<bool>>& visited){
    if (x < 0 || y < 0 || x >= n || y>=m) return false;
    if (x+1 < 0 || y < 0 || x >= n || y>=m) return false;
    if (x < 0 || y+1 < 0 || x >= n || y>=m) return false;
    if (x+1 < 0 || y+1 < 0 || x >= n || y>=m) return false;

    if (visited[x][y]) return false;
    if (maze[x][y] == '#') return false;
    if (maze[x+1][y+1] == '#') return false;
    if (maze[x+1][y] == '#') return false;
    if (maze[x][y+1] == '#') return false;

    return true;
}

bool walk(int x,int y,vector<vector<bool>>& visited){

    if (!valid_point(x,y,visited)) return false;
    // cout << "I'm at " << x << " " << y << "\n";
    visited[x][y] = true;
    if (x == n-2) return true;
    if (walk(x+1,y,visited)) return true;
    if (walk(x-1,y,visited)) return true;
    if (walk(x,y+1,visited)) return true;
    if (walk(x,y-1,visited)) return true;
    
    return false;

}

int main() {

    
    cin >> n >> m;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for (int i = 0;i<n;i++){
        cin >> input;
        maze.push_back(input);
    }
    // find start point
    for (int y = 0;y<m;y++){

        if (walk(0,y,visited)){
            cout << "yes";
            return 0;
        }
        
    }
    cout << "no";
return 0;
    }
    
