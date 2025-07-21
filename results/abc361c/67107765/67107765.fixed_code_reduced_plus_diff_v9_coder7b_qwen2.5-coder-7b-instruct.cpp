#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // The optimal strategy is to remove the smallest K/2 elements and the largest K/2 elements
    int del = k / 2;
    int ans = nums[n - del - 1] - nums[del];

    // If K is odd, we need to consider removing one more element to minimize the difference further
    if(k % 2 != 0) {
        ans = min(ans, min(nums[n - del - 2] - nums[del], nums[n - del] - nums[del + 1]));
    }

    cout << ans << endl;

    return 0;
}