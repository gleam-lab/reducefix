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

    int ans = INT_MAX;
    for(int i = 0; i <= k; i++) {
        int left_max = max(nums[i], nums[n-k+i-1]);
        int right_min = min(nums[k-i], nums[n-1-i]);
        ans = min(ans, left_max - right_min);
    }

    cout << ans << endl;

    return 0;
}