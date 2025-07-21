#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long min_val = LLONG_MAX, max_val = LLONG_MIN;
    for(int i = 0; i <= n-k; ++i) {
        min_val = min(min_val, nums[i]);
        max_val = max(max_val, nums[i+k-1]);
    }

    cout << max_val - min_val << endl;

    return 0;
}