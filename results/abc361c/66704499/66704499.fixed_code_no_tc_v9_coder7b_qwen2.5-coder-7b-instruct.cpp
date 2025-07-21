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

    int l = 0;
    int r = n - 1;

    while (k--) {
        // Calculate the difference between the current max and min values
        int diff = nums[r] - nums[l];
        // If removing the smallest element results in a smaller difference, do so
        if (diff >= nums[r] - nums[l+1]) {
            r--;
        } 
        // Otherwise, remove the largest element
        else {
            l++;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}