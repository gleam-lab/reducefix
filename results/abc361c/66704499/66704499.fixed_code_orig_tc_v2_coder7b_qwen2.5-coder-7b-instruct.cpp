#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int max_val = nums[min(n - 1, i + k)];
        int min_val = nums[max(0, i - 1)];
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;

    return 0;
}