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
        int median = nums[(r+l+1) / 2];
        int dl = abs(median - nums[l]);
        int dr = abs(median - nums[r]);
        // cout << "MEDIAN: " << median << endl;
        // cout << "L:" << nums[l] << endl;
        // cout << "DL: " << dl << endl;
        // cout << "R:" << nums[r] << endl;
        // cout << "DR: " << dr << endl;

        if (dl > dr){
            l++;
        }
        else {
            r--;
        }
    }

    // cout << "NUM L:" << nums[l] << endl;
    // cout << "NUM R:" << nums[r] << endl;
    cout << nums[r] - nums[l] << endl;

    return 0;
}
