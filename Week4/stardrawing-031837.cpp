#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>
#include <string>
#include <functional>
#include <set>
#include <algorithm>

using namespace std;

int vertex, edge;
vector<int> star_node;
pair<int, int> info;
set<vector<int>> star_noose;
unordered_set<int> linear;
unordered_set<int> circle;


int count_length(vector<vector<int>>& adjlist, vector<bool>& visited, int node)
{
    if (visited[node])
        return 0;
    int len = 0;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        visited[node] = true;
        len++;
        for (auto it : adjlist[node])
        {
            if (visited[it])
                continue;
            q.push(it);
        }
    }

    return len;
}

pair<int, int> countVE(vector<vector<int>>& adjlist, vector<bool>& visited, int node)
{
    int v = 0, e = 0;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        v++;

        for (auto it : adjlist[node])
        {
            q.push(it);
            e++;
        }
    }

    e /= 2;

    return make_pair(v, e);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertex >> edge;

    vector<vector<int>> adjlist(vertex + 1);
    vector<bool> visited(vertex + 1, false);
    vector<int> counter(vertex + 1, 0);
    int x, y;

    for (int i = 0; i < edge; i++)
    {

        cin >> x >> y;

        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
        counter[x]++;
        counter[y]++;
        if (counter[x] == 3)
            star_node.push_back(x);
        if (counter[y] == 3)
            star_node.push_back(y);
    }
    // cout << "star section\n";
    for (auto node : star_node)
    {
        // หาความยาวเส้น บ่วง ดาว
        vector<int> tmp_vector;
        visited[node] = true;

        int one = count_length(adjlist, visited, adjlist[node][0]);
        int two = count_length(adjlist, visited, adjlist[node][1]);
        int three = count_length(adjlist, visited, adjlist[node][2]);
        if (two == 0)
        {
            tmp_vector = { 0, one, three }; // 0 ขนาดลูกตุ้ม ขนาดสาย
        }
        else if (three == 0)
        {
            tmp_vector = { 0, two, one }; // 0 ขนาดลูกตุ้ม ขนาดสาย
        }
        else {
            tmp_vector = { one,two,three };
            sort(tmp_vector.begin(), tmp_vector.end());
        }


        // cout << "From node " << node << " : ";
        // for (auto p : tmp_vector)
        //     cout << p << " ";
        // cout << "\n";
        star_noose.insert(tmp_vector);
    }

    // cout << "non-star section\n";
    for (int i = 1; i <= vertex; i++)
    {
        if (visited[i])
            continue;
        info = countVE(adjlist, visited, i);
        int v = info.first;
        int e = info.second;
        // cout << "at vertex " << i << " : " << v << " " << e << "\n";
        if (v == e)
        {
            circle.insert(v);
        }
        else if (v == e + 1)
        {
            linear.insert(v);
        }
        else
        {
            // cout << "Somethings went wrong\n";
        }
    }
    // cout << star_noose.size() << " " << circle.size() << " " << linear.size() << "\n";
    cout << star_noose.size() + circle.size() + linear.size() << "\n";

    return 0;
}
