#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int left_index = 0, right_index = n - 1;

    // We need to remove k largest elements to minimize the max-min difference
    // This means we will keep the smallest elements possible after removing k elements
    while (k--) {
        // Remove the largest element
        right_index--;
    }

    // The minimum possible value of B is nums[left_index + k]
    // The maximum possible value of B is nums[right_index]
    // The difference is the answer
    cout << nums[right_index] - nums[left_index + k] << endl;

    return 0;
}