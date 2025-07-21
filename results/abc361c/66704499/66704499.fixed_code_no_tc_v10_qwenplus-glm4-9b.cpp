#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Use two pointers to find the optimal way to remove elements
    auto maxmin_diff = numeric_limits<int>::min();
    for (int remove_left = 0; remove_left <= k; remove_left++) {
        int remove_right = k - remove_left;
        int left_max = INT_MIN, right_min = INT_MAX;

        // Find the max in the left part that is not removed
        for (int i = 0; i <= remove_left; i++) {
            left_max = max(left_max, nums[i]);
        }

        // Find the min in the right part that is not removed
        for (int i = n - 1; i >= n - remove_right; i--) {
            right_min = min(right_min, nums[i]);
        }

        // Calculate the difference and update the result
        maxmin_diff = max(maxmin_diff, left_max - right_min);
    }

    cout << maxmin_diff << endl;

    return 0;
}