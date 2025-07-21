#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    double min_diff = numeric_limits<double>::max();
    double max_value = -1e9, min_value = 1e9; // Initialize to extreme values.

    // Iterate over the sorted array and simulate the removal of K elements.
    for (int i = 0; i <= n - k; ++i) {
        double current_max = nums[n - k + i];
        double current_min = nums[i]; // Current min is the first element that will remain after i elements are removed.

        if (current_max - current_min < min_diff) {
            min_diff = current_max - current_min;
            max_value = current_max;
            min_value = current_min;
        }
    }

    // Output the minimum possible value of the maximum and minimum of the remaining elements.
    cout << static_cast<int>(min_diff) << endl;

    return 0;
}