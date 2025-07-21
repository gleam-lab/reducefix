#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int min_diff = INT_MAX;

    for (int i = 0; i <= n - k; i++) {
        int max_val = nums[i + k - 1];
        int min_val = nums[i];
        int diff = max_val - min_val;
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}