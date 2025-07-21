#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Sort the array to easily find the minimum and maximum of the remaining elements after removal.
    sort(nums.begin(), nums.end());

    // Remove the k largest elements from both ends to minimize the difference between the max and min of the remaining elements.
    for (int i = 0; i < k; i++) {
        nums.pop_back(); // Remove largest element from the end
    }
    for (int i = 0; i < k; i++) {
        nums.erase(nums.begin()); // Remove largest element from the start
    }

    // After removing k elements, the difference between the max and min of the remaining elements will be the answer.
    int min_value = *min_element(nums.begin(), nums.end());
    int max_value = *max_element(nums.begin(), nums.end());
    cout << max_value - min_value << endl;

    return 0;
}