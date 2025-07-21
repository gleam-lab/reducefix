#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums + n);

    // Initialize left and right pointers
    int l = 0;
    int r = n - 1;

    // Remove k elements to minimize the difference between max and min values in the resulting sequence
    while (k--) {
        // Compare the absolute differences between the middle element and the current left and right elements
        if (abs(nums[(r+l)/2] - nums[l]) > abs(nums[(r+l)/2] - nums[r])) {
            // If removing the leftmost element results in a smaller difference, move the left pointer to the right
            l++;
        } else {
            // Otherwise, move the right pointer to the left
            r--;
        }
    }

    // The result is the difference between the new maximum and minimum values
    cout << nums[r] - nums[l] << endl;

    return 0;
}