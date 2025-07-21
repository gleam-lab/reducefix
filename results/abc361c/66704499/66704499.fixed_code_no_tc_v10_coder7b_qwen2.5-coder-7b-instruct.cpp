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
        // Choose the optimal end point to minimize the difference between max and min values
        if (nums[r] - nums[l+1] <= nums[r-1] - nums[l]) {
            l++; // Remove the smaller number from the start to increase the range size
        } else {
            r--; // Remove the larger number from the end to decrease the range size
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}