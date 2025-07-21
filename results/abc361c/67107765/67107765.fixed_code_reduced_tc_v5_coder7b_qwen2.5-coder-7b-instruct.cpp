#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // Calculate the minimum difference after removing k elements
    long long ans = LLONG_MAX;
    for(int i = 0; i <= n - k; ++i) {
        ans = min(ans, nums[i + k - 1] - nums[i]);
    }

    cout << ans << '\n';

    return 0;
}