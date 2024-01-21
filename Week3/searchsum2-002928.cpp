#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySize(const vector<int>& nums, int k) {
    int n = nums.size();
    int start = 0;
    int maxSize = 0;
    int currentSum = 0;

    for (int end = 0; end < n; ++end) {
        currentSum += nums[end];

        while (currentSum > k) {
            currentSum -= nums[start];
            ++start;
        }


        maxSize = max(maxSize, end - start + 1);
    }

    return maxSize;
}
int main() {

    int n, k;
    cin >> n >> k;
    vector<int> v;
    int tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    int c;
    for (int i = 0;i<k;i++){    
        cin >> c;
        int result = maxSubarraySize(v, c);
    cout << result << "\n";
}
    return 0;
}
