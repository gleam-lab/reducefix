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
        // We should always try to minimize the difference between the max and min
        // So we choose the element which will make the difference smaller
        // If removing the larger element makes the difference smaller, we remove it
        // Otherwise, we remove the smaller one
        if ((nums[r] - nums[l]) > (nums[r-1] - nums[l+1])){
            r--;
        } else {
            l++;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}