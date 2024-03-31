#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <utility>
#include <iomanip>
#include <deque>
#include <cstdlib>
#include "traffic.h"

using namespace std;

int n,k;
set<vector<int>> ans;
void helper(int x, int start, int end, int state)
{
  if (start == end)
    return;
  int mid = (start + end) / 2;
  if (start + 1 == mid)
  {
    if (traffic_query(x, start, x, mid) == 2)
      ans.insert({x, start, x, mid});
  }
  if (mid + 1 == end)
  {
    if (traffic_query(x, mid, x, end) == 2)
      ans.insert({x, mid, x, end});
    return;
  }
  int res1 = traffic_query(x, start, x, mid);

  if (state)
  {
    if (res1 == (mid - start + 1) + 1)
      return helper(x, start, mid, 1);
    if (res1 == (mid - start + 1))
    {
      helper(x, start, mid, 0);
      helper(x, mid, end, 0);
      return;
    }
    return helper(x, mid, end, 1);
  }
  else
  {
    if (res1 == (mid - start + 1))
      return helper(x, start, mid, 0);
    return helper(x, mid, end, 0);
  }
}

void helper2(int y, int start, int end, int state)
{
  if (start == end)
    return;
  int mid = (start + end) / 2;
  if (start + 1 == mid)
  {
    if (traffic_query(start, y, mid, y) == 2)
      ans.insert({start, y, mid, y});
  }
  if (mid + 1 == end)
  {
    if (traffic_query(mid, y, end, y) == 2)
      ans.insert({mid, y, end, y});
    return;
  }
  
  int res1 = traffic_query(start, y, mid, y);
  if (state)
  {
    if (res1 == (mid - start + 1) + 1)
      return helper2(y, start, mid, 1);
    if (res1 == (mid - start + 1))
    {
      helper2(y, start, mid, 0);
      helper2(y, mid, end, 0);
      return;
    }
    return helper2(y, mid, end, 1);
  }
  else
  {
    if (res1 == (mid - start + 1))
      return helper2(y, start, mid, 0);
    return helper2(y, mid, end, 0);
  }

}

int main()
{
  traffic_init(&n, &k);
  int counter = 0;
  // vertical run
  for (int i = 1; i <= n; i++)
  {
    if (ans.size() >= n)
      break;
    int tmp = traffic_query(i, 1, i, n);
    if (tmp >= n)
      helper(i, 1, n, (int)(tmp != n));
  }
  // horizontal run
  for (int i = 1; i <= n; i++)
  {
    if (ans.size() >= n)
      break;
    int tmp = traffic_query(1, i, n, i);
    if (tmp >= n)
      helper2(i, 1, n, (int)(tmp != n));
  }
  vector<vector<int>> vec;
  for (auto &it : ans)
    vec.push_back(it);
  vec.push_back({0, 0, 0, 0});
  traffic_report(vec[0][0], vec[0][1], vec[0][2], vec[0][3], vec[1][0], vec[1][1], vec[1][2], vec[1][3]);
  return 0;
}