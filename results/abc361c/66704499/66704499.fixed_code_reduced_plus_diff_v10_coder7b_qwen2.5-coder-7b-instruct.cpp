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

    int min_range = INT_MAX;

    for (int i = 0; i <= n - k; i++) {
        min_range = min(min_range, nums[i + k - 1] - nums[i]);
    }

    cout << min_range << endl;

    return 0;
}