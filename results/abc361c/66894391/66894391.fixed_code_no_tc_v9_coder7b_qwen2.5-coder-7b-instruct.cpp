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
        // Remove the element that would maximize the difference after removal
        if (nums[l] <= nums[r]) {
            l++;
        } else {
            r--;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}