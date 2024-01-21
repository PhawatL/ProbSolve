// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;


int w, h;
vector<string> building;
string str_input;


vector<int> make_move(int x, int y, int direction, vector<string>& building) {

    if (building[x][y] == '.') {
        return { x + 1,y,direction };
    }

    if (direction == 1) {
        if (y == w - 1) return { x,y,-1 };
        return { x,y + direction,direction };
    }
    else {
        if (y == 0) return { x,y,1 };
        return { x,y + direction,direction };

    }


}
bool traverse(int x, int y, int direction, vector<string>& building, vector<vector<pair<bool, bool>>>& visited, vector<vector<pair<bool, bool>>>& memory) {

    if (building[x][y] == '$') {
        return true;
    }
    if (building[x][y] == '@') return false;

    vector<int>mov(3);
    bool answer;
    if (direction == 1) {
        if (visited[x][y].first) return memory[x][y].first;

        mov = make_move(x, y, direction, building);
        answer = traverse(mov[0], mov[1], mov[2], building, visited, memory);
        memory[x][y].first = answer;
        visited[x][y].first = true;
    }
    else {
        if (visited[x][y].second) return memory[x][y].second;

        mov = make_move(x, y, direction, building);
        answer = traverse(mov[0], mov[1], mov[2], building, visited, memory);
        memory[x][y].second = answer;
        visited[x][y].second = true;

    }
    return answer;
}
void printMemory(const std::vector<std::vector<std::pair<bool, bool>>>& myVector) {
    for (const auto& outerVector : myVector) {
        for (const auto& innerPair : outerVector) {
            std::cout << "(" << innerPair.first << ", " << innerPair.second << ") ";
        }
        std::cout << std::endl;
    }
}

int reach = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    vector<vector<pair<bool, bool>>> memory(h, vector<pair<bool, bool>>(w, make_pair(false, false)));
    vector<vector<pair<bool, bool>>> visited(h, vector<pair<bool, bool>>(w, make_pair(false, false)));

    for (int i = 0; i < h; i++) {
        cin >> str_input;
        building.push_back(str_input);
    }

    // print input
    // cout << "input : \n";

    //  for (auto i:building){
    //     cout << i << "\n";
    //  }
    //  cout << "\n";

    // first answer

    for (int j = 0; j < w; j++) {

        // cout << "\tbot start here : " << 0 << " " << j << "\n\n"; 

        if (traverse(0, j, 1, building, visited, memory)) {
            reach++;
        }
        if (traverse(0, j, -1, building, visited, memory)) {
            reach++;
        }
    }
    // printMemory(memory);

    cout << reach << " ";

    // second answer
    int reach_max = 0;

    for (int d = 0; d < h - 1; d++) {
        for (int it = 0; it < w; it++) {
            if (building[d][it] == '#' && (visited[d][it].first || visited[d][it].second)) {
                // int drill = h-2;
                reach = 0;
                // while(drill >=0 && building[drill][it] != '#'){

                //     drill--;

                // }
                // if (drill < 0) continue;
                // cout << "\n" << drill << ", " << it << "\n";
                building[d][it] = '.';
                // cout << "building : \n";

                // for (auto b:building){
                //     cout << b << "\n";
                // }
                // cout << "\n";
                vector<vector<pair<bool, bool>>> new_visited(h, vector<pair<bool, bool>>(w, make_pair(false, false)));

                for (int i = d + 1; i < h; ++i) {
                    for (int j = 0; j < w; ++j) {
                        if (i < h && j < w) {
                            new_visited[i][j] = visited[i][j];
                        }
                    }
                }

                for (int j = 0; j < w; j++) {
                    // cout << "\tbot start here : " << 0 << " " << j << "\n\n"; 


                    if (traverse(0, j, 1, building, new_visited, memory)) {
                        reach++;
                    }
                    if (traverse(0, j, -1, building, new_visited, memory)) {
                        reach++;
                    }

                }
                // cout << reach << " ";
                building[d][it] = '#';
                // if (reach > reach_max) cout << d << ", " << it << " : " << reach <<  "\n";
                reach_max = max(reach, reach_max);
            }

        }

    }
    cout << "" << reach_max << "\n";






    return 0;
}