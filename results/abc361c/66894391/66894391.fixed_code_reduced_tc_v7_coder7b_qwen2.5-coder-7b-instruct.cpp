#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long min_diff = LLONG_MAX;
    for (int i = 0; i <= n - k; i++) {
        min_diff = min(min_diff, static_cast<long long>(nums[i + k - 1]) - nums[i]);
    }

    cout << min_diff << endl;

    return 0;
}