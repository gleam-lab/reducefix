#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void) {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int min_diff = INT_MAX;

    // Iterate through all possible pairs of indices (l, r) such that r - l = k
    for (int l = 0; l <= n - k - 1; ++l) {
        int r = l + k;
        int current_diff = nums[r] - nums[l];
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << endl;

    return 0;
}