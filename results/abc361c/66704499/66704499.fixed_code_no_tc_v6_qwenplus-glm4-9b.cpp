#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    // Read the array
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }

    // Sort the array to easily remove the largest elements
    sort(nums.begin(), nums.end());

    // We will remove the largest k elements to minimize the range
    // So we need to consider the array from the end
    int min_value = nums[n - k]; // Minimum value will be the k-th largest element
    int max_value = nums[n - 1]; // Maximum value will be the largest element

    // Output the difference between the maximum and minimum values
    cout << max_value - min_value << endl;

    return 0;
}