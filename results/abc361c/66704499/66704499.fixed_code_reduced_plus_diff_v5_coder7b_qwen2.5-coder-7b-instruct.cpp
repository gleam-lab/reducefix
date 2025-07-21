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
        if (nums[r] - nums[l] > nums[r-1] - nums[l+1]) {
            r--;
        } else {
            l++;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}