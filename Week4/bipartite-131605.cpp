#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

bool dfs(vector<list<int>>& adjlist, vector<int>& color_list, int node, int color) {
    if (color_list[node] != 0) {
        return color_list[node] == color;
    } else {
        color_list[node] = color;
        for (auto &it : adjlist[node]) {
            if (!dfs(adjlist, color_list, it, -color)) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int loop, vertices, edges;

    cin >> loop;

    for (int i = 0; i < loop; i++) {
        cin >> vertices >> edges;
        vector<list<int>> adjlist(vertices + 1);
        vector<int> color_list(vertices + 1, 0);

        for (int j = 0; j < edges; j++) {
            int u, v;
            cin >> u >> v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        bool is_bipartite = true;

        for (int node = 1; node <= vertices; ++node) {
            if (!color_list[node]) {
                if (!dfs(adjlist, color_list, node, 1)) {
                    is_bipartite = false;
                    break;
                }
            }
        }

        if (is_bipartite) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}