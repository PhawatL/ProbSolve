// #include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <iomanip>
#define INT_MAX 2000000000
using namespace std;

void printVisited(const vector<vector<int>> &visited)
{
    cout << "Visited Array:" << endl;
    for (int i = 0; i < visited.size(); ++i)
    {
        for (int j = 0; j < visited[i].size(); ++j)
        {
            cout << setw(3) << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}
int n, m;
string input;
vector<string> maze;
vector<int> dir{0, 1, 0, -1}; //  y = {1,0,-1,0}

bool valid_point(int x, int y, vector<vector<int>> &visited)
{
    if (visited[x][y] != INT_MAX)
        return false;
    if (maze[x][y] == '#')
        return false;
    if (maze[x][y] == '*')
        return false;
    return true;
}

void walk(int x, int y, vector<vector<int>> &visited, int a, int b)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = 0;
    while (!q.empty())
    {

        x = q.front().first;
        y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {

            if (valid_point(x + dir[i], y + dir[(i + 1) % 4], visited))
            {

                // if (maze[x + dir[i]][y + dir[(i + 1) % 4]] == '.')
                // {
                q.push(make_pair(x + dir[i], y + dir[(i + 1) % 4]));
                visited[x + dir[i]][y + dir[(i + 1) % 4]] = min(visited[x + dir[i]][y + dir[(i + 1) % 4]], visited[x][y] + 1);
                // }
                // else if (maze[x + dir[i]][y + dir[(i + 1) % 4]] == '|' && (i == 1 || i == 3))
                // {
                //     q.push(make_pair(x + dir[i], y + dir[(i + 1) % 4]));
                //     visited[x + dir[i]][y + dir[(i + 1) % 4]] = min(visited[x + dir[i]][y + dir[(i + 1) % 4]], visited[x][y] + 1);
                // }
                // else if (maze[x + dir[i]][y + dir[(i + 1) % 4]] == '-' && (i == 0 || i == 2))
                // {
                //     q.push(make_pair(x + dir[i], y + dir[(i + 1) % 4]));
                //     visited[x + dir[i]][y + dir[(i + 1) % 4]] = min(visited[x + dir[i]][y + dir[(i + 1) % 4]], visited[x][y] + 1);
                // }
            }
        }

        // cout << "stand at -> " << x << " " << y << "\n";
    }
}
int x, y, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> x >> y >> a >> b;
    vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        maze.push_back(input);
    }

    walk(x - 1, y - 1, visited, a - 1, b - 1);
    int curr_min = visited[a - 1][b - 1];
    // cout << curr_min << "\n";
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {

            if (maze[i][j] == '*')
            { 
                if ((maze[i-1][j] == '.' && maze[i+1][j] == '.') || maze[i][j-1] == '.' && maze[i][j+1] == '.')
                {
                    maze[i][j] = '.';
                    vector<vector<int>> n_visited(n, vector<int>(m, INT_MAX));
                    walk(x - 1, y - 1, n_visited, a - 1, b - 1);
                    curr_min = min(curr_min, n_visited[a - 1][b - 1]);
                    maze[i][j] = '*';
                }

            }
        }
    }

    if (curr_min == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << curr_min << "\n";
    }

    return 0;
}