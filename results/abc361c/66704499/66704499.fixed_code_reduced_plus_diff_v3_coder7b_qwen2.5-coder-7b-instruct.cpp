#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void) {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int min_diff = INT_MAX;
    for (int i = 0; i <= n - k; i++) {
        min_diff = min(min_diff, nums[i + k - 1] - nums[i]);
    }

    cout << min_diff << endl;

    return 0;
}