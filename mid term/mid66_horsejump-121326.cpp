#include <bits/stdc++.h>
#define INT_MAX 1000000000
using namespace std;

int n, gob_ans;
string input;
vector<string> maze;
vector<int> dir{0, 1, 0, -1}; //  y = {1,0,-1,0}

bool valid_point(int x, int y, vector<vector<int>> &visited){
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (visited[x][y] != INT_MAX) return false;
    if (maze[x][y] == '#') return false;
    return true;
}

bool valid_points(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    if (maze[x][y] == '#')
        return false;
    return true;
}

void walk(int x, int y, vector<vector<int>> &level){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    level[x][y] = 0;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (valid_point(x + dir[i], y + dir[(i + 1) % 4], level))
            {
                q.push(make_pair(x + dir[i], y + dir[(i + 1) % 4]));
                level[x + dir[i]][y + dir[(i + 1) % 4]] = min(level[x + dir[i]][y + dir[(i + 1) % 4]], level[x][y] + 1);
            }
        }
    }
}
void solve(int x, int y, int wei, vector<vector<int>> &level){
    if (valid_points(x - 2, y - 1))gob_ans = min(gob_ans, wei + level[x - 2][y - 1]);
    if (valid_points(x - 2, y + 1))gob_ans = min(gob_ans, wei + level[x - 2][y + 1]);
    if (valid_points(x - 1, y - 2))gob_ans = min(gob_ans, wei + level[x - 1][y - 2]);
    if (valid_points(x - 1, y + 2))gob_ans = min(gob_ans, wei + level[x - 1][y + 2]);
    if (valid_points(x + 1, y - 2))gob_ans = min(gob_ans, wei + level[x + 1][y - 2]);
    if (valid_points(x + 1, y + 2))gob_ans = min(gob_ans, wei + level[x + 1][y + 2]);
    if (valid_points(x + 2, y - 1))gob_ans = min(gob_ans, wei + level[x + 2][y - 1]);
    if (valid_points(x + 2, y + 1))gob_ans = min(gob_ans, wei + level[x + 2][y + 1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        maze.push_back(input);
    }
    vector<vector<int>> level_end(n, vector<int>(n, INT_MAX));
    vector<vector<int>> level_start(n, vector<int>(n, INT_MAX));
    walk(n - 1, n - 1, level_end);
    walk(0, 0, level_start);
    gob_ans = level_start[n - 1][n - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (valid_points(i, j))
                solve(i, j, level_start[i][j] + 1, level_end);
        }
    }
    cout << gob_ans;
    return 0;
}