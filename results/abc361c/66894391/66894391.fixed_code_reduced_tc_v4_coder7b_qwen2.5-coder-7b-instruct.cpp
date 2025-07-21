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

    int result = INT_MAX;

    for (int i = 0; i <= n - k; i++) {
        int min_val = nums[i];
        int max_val = nums[i + k - 1];
        result = min(result, max_val - min_val);
    }

    cout << result << endl;

    return 0;
}