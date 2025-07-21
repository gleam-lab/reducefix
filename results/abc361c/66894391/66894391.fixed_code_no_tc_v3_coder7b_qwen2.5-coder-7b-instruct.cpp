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
        int dl = abs(nums[l + 1] - nums[l]);
        int dr = abs(nums[r] - nums[r - 1]);
        // If removing the left element results in a smaller difference, do so
        if (dl <= dr){
            l++;
        }
        // Otherwise, remove the right element
        else {
            r--;
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}