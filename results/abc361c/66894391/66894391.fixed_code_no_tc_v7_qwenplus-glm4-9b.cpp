#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Sort the array to facilitate the removal of elements
    sort(nums.begin(), nums.end());

    // Initialize pointers for the smallest and largest elements
    int l = 0, r = n - 1;

    // Remove the first k elements from the extremes
    for (int i = 0; i < k; i++) {
        l++;
    }
    for (int i = 0; i < k; i++) {
        r--;
    }

    // The minimum possible value of the maximum and minimum in the new sequence
    // is now between the smallest element removed and the largest element removed
    // or the largest element remaining and the smallest element remaining.
    // Since the array is sorted, we just need to print the difference between
    // the last element of the smallest part and the first element of the largest part.
    cout << nums[r] - nums[l] << endl;

    return 0;
}