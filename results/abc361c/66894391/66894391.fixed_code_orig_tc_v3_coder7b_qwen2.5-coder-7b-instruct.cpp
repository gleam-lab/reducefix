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

    int ans = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, nums[n - k + i] - nums[i]);
    }

    cout << ans << endl;
    return 0;
}