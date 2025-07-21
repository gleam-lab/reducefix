#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // The minimum difference starts with the difference between the max and min of the array
    int min_diff = nums[n - 1] - nums[0];

    // We will consider removing K elements from the two ends of the array
    for (int i = 0; i <= n - k - 1; i++) {
        // The maximum possible value of B is the maximum value in the subarray from i to n-k-1
        // The minimum possible value of B is the minimum value in the subarray from i+k to n-1
        int max_val = *max_element(nums.begin() + i, nums.begin() + n - k);
        int min_val = *min_element(nums.begin() + i + k, nums.begin() + n);
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;

    return 0;
}