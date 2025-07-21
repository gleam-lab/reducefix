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
        int median = nums[(l+r) / 2]; // Change here
        int dl = abs(median - nums[l]);
        int dr = abs(median - nums[r]);

        if (dl <= dr){ // Change here
            l++;
        }
        else {
            r--;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}