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
        int median = nums[(r+l) / 2]; // Corrected index calculation for median
        int dl = abs(median - nums[l]);
        int dr = abs(median - nums[r]);

        if (dl > dr){
            l++; // Move left pointer to minimize the difference
        }
        else {
            r--; // Move right pointer to minimize the difference
        }
    }

    cout << nums[r] - nums[l] << endl;

    return 0;
}