#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int island, bridge, start, des;

int bfs(vector<vector<vector<int>>> &adjlist, int start_island, int des_island, int color_mode)
{
    vector<int> level(island + 1, -1);
    queue<int> q;
    q.push(start_island);
    level[start_island] = 0;
    int current_island;
    while (!q.empty())
    {
        current_island = q.front();
        q.pop();
        for (auto &it : adjlist[0][current_island])
        {

            if (level[it] != -1)
            {
                continue;
            }
            level[it] = level[current_island] + 1;
            if (it == des_island)
                break;
            q.push(it);
        }
        for (auto &it : adjlist[color_mode][current_island])
        {

            if (level[it] != -1)
            {
                continue;
            }
            level[it] = level[current_island] + 1;
            if (it == des_island)
                break;
            q.push(it);
        }
    }
    return level[des_island];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> island >> bridge >> start >> des;

    vector<vector<vector<int>>> adjlist(3, vector<vector<int>>(island + 1));
    int a, b, color;

    for (int i = 0; i < bridge; i++)
    {
        cin >> a >> b >> color;
        adjlist[color][a].push_back(b);
        adjlist[color][b].push_back(a);
    }

    int min_step = bridge * 2;
    int tmp = bfs(adjlist,start,des,2);
    if (tmp != -1){
        min_step = min(min_step,tmp);
    } 
    tmp = bfs(adjlist, start, des, 1);
    if (tmp != -1) {
        min_step = min(min_step, tmp);
    }
    if (min_step == bridge * 2)
        min_step = -1;
    
    cout << min_step << '\n';

    return 0;
}
