#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int result = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        int left = i;
        int right = n - 1 - (k - i);
        if (left > right) continue;
        result = min(result, nums[right] - nums[left]);
    }
    cout << result << endl;
    return 0;
}