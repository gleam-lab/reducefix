#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    long long l = nums[0], r = nums[n-1];
    long long ans = LLONG_MAX;

    while (l <= r) {
        long long mid = (l + r) / 2;
        int left = upper_bound(nums, nums + n, mid) - nums; // Elements greater than or equal to mid
        int right = n - left; // Elements less than mid

        // Check if we can remove exactly k elements
        if (left - 1 >= k && right - 1 >= n - k) {
            long long max_val = max(nums[n-k-1], mid);
            long long min_val = min(nums[k], mid);
            ans = min(ans, max_val - min_val);
        }

        // Adjust binary search range
        if (left - 1 > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}