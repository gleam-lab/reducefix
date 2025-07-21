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

    long long min_diff = LLONG_MAX;
    long long max_val = 0;
    long long min_val = LLONG_MAX;

    // Start with the largest window of size K
    for (int i = k - 1; i < n; ++i) {
        max_val = max(max_val, nums[i]);
        min_val = min(min_val, nums[i - k + 1]);
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;

    return 0;
}