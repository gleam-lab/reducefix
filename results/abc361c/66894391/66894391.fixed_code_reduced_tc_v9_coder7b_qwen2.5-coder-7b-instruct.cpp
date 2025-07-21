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
        int dl = nums[l + 1] - nums[l];
        int dr = nums[r] - nums[r - 1];
        // cout << "DL: " << dl << endl;
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