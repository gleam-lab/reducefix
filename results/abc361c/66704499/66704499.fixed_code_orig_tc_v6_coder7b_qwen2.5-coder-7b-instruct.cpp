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

    // Calculate the initial range with all elements
    int initial_range = nums[n - 1] - nums[0];

    // Iterate over possible positions for the median
    int min_range = initial_range;
    for (int i = k; i <= n - k; i++) {
        min_range = min(min_range, nums[i + k - 1] - nums[i]);
    }

    cout << min_range << endl;

    return 0;
}