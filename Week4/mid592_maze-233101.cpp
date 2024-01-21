#include <bits/stdc++.h>
using namespace std;

    
int n,q;
string input;
vector<string>maze;


bool valid_point(int x,int y,vector<vector<bool>>& visited){
    if (x < 0 || y < 0 || x >= n || y>=n) return false;
    if (maze[x][y] == '#') return false;
    if (visited[x][y]) return false;
    return true;
}

void walk(int x,int y,vector<vector<bool>>& visited,int a,int b,int key){

    if (!valid_point(x,y,visited)) return ;
    // cout << "I'm at " << x << " " << y << "\n";
    if (maze[x][y] == 'O'){
        if (key == 1) key--;
        else return ;
    }
    visited[x][y] = true;
    if (visited[a][b]) return ;
    walk(x+1,y,visited,a,b,key);
    walk(x-1,y,visited,a,b,key);
    walk(x,y+1,visited,a,b,key);
    walk(x,y-1,visited,a,b,key);
    
    return ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        
    cin >> n >> q;
    
    for (int i = 0;i<n;i++){
        cin >> input;
        maze.push_back(input);
    }
    int x,y,a,b;
    for (int i = 0;i<q;i++){
        cin >> x >> y >> a >> b;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        walk(x-1,y-1,visited,a-1,b-1,1);
        if (visited[a-1][b-1]) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

return 0;
    }
    
