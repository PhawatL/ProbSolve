#include <bits/stdc++.h>
#include "probelib.h" 
using namespace std;

int solve(int start,int end){
    if (end <= start)
        return start;
    int mid = (start + end) / 2;
    if (probe_check(0,mid))
        return solve(start,mid);
    else
        return solve(mid+1,end);
}
int main()
{
    probe_answer(solve(0,probe_init()-1));
    return 0;
}