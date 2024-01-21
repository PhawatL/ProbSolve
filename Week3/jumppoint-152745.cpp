#include <bits/stdc++.h>

using namespace std;

int x, y, loop;
double r;
int True_Answer = 0;
map<pair<int, int>, int> m;
map<pair<int, int>, bool> visited;

void printMapB(const std::map<std::pair<int, int>, bool>& myMap) {
    for (const auto& entry : myMap) {
        const auto& key = entry.first;
        bool value = entry.second;

        std::cout << "Key: (" << key.first << ", " << key.second << "), Value: " << std::boolalpha << value << std::endl;
    }
}
void printMapI(const std::map<std::pair<int, int>, int>& myMap) {
    for (const auto& entry : myMap) {
        const auto& key = entry.first;
        const auto& value = entry.second;
        std::cout << "Key: (" << key.first << ", " << key.second << "), Value: " << value << std::endl;
    }
}


double nom(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

vector<pair<int, int>> find_point(pair<int, int> start_point, map<pair<int, int>, int> &m) {
    vector<pair<int, int>> ans;
    for (const auto &it : m) {
        if (nom(it.first.first, it.first.second, start_point.first, start_point.second) < r + 1e-4) {
            ans.push_back(it.first);
        }
    }
    return ans;
}

pair<int, int> idk_of_min_value(map<pair<int, int>, int> &m) {
    int ans = INT_MAX;
    pair<int, int> a = make_pair(-1, -1);
    for (const auto &it : m) {
        if (!visited[it.first]) {
            if (it.second < ans) {
                ans = it.second;
                a = it.first;
            }
        }
    }
    return a;
}

int main() {
    cin >> loop >> r;

    m[make_pair(0, 0)] = 0;
    m[make_pair(100, 100)] = INT_MAX;

    for (int i = 0; i < loop; i++) {
        cin >> x >> y;
        m[make_pair(x, y)] = INT_MAX;
        visited[make_pair(x, y)] = false;
    }

    pair<int, int> point = make_pair(0, 0);
    while (1) {
        
        visited[point] = true;
        vector<pair<int, int>> tmp_vec;
        tmp_vec = find_point(point, m);
        for (const auto it : tmp_vec) {
            m[it] = min(m[it], m[point] + 1);
        }
        point = idk_of_min_value(m);
        if ((point.first == -1) || visited[make_pair(100, 100)]) {
            break;
        }
    // printMapB(visited);
    // printMapI(m);
    // cout <<  "\n";
    }

    if (visited[make_pair(100, 100)]) {
        cout << m[make_pair(100, 100)];    
    } else {
        cout << "-1";
    }

    return 0;
}
