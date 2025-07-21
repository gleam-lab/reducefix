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
        // Remove the larger end if the difference is smaller or equal to remove the smaller one
        if ((nums[r] - nums[l]) >= (nums[l+k] - nums[r-k])) {
            r--;
        } else {
            l++;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}