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
        int dl = nums[l + 1] - nums[l]; // Difference between adjacent elements at the left end
        int dr = nums[r] - nums[r - 1]; // Difference between adjacent elements at the right end

        // Remove the element which results in a smaller difference after removal
        if (dl <= dr) { // If removing from the left end makes less change
            l++;
        } else {
            r--;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}