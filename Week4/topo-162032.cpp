#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

stack<int> answer;

bool is_cycle(vector<list<int>>& adjlist, vector<bool>& visited, int node, int snode) {
    if (visited[node]) return false;
    visited[node] = true;

    for (const auto& it : adjlist[node]) {
        if (it == snode || is_cycle(adjlist, visited, it, snode))
            return true;
    }

    visited[node] = false;  
    return false;
}

void topological_sort(vector<list<int>>& adjlist, vector<bool>& visited, int start_node) {
    if (visited[start_node]) return;
    visited[start_node] = true;

    for (const auto& it : adjlist[start_node]) {
        topological_sort(adjlist, visited, it);
    }
    answer.push(start_node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    vector<list<int>> adjlist(x + 1);
    vector<bool> zero_in_order(x + 1, true);

    for (int j = 0; j < y; j++) {
        int u, v;
        cin >> u >> v;
        zero_in_order[v] = false;
        adjlist[u].push_back(v);
    }

    vector<int> start_node;

    for (int it = 1; it <= x; it++) {
        vector<bool> visited(x + 1, false);

        if (zero_in_order[it])
            start_node.push_back(it);
    }

    // topological sort
    vector<bool> visited(x + 1, false);
    for (const auto& it : start_node) {
        topological_sort(adjlist, visited, it);
    }

    while (!answer.empty()) {
        cout << answer.top() << "\n";
        answer.pop();
    }

    return 0;
}