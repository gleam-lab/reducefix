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

    // After sorting, the smallest k elements should be removed
    int result = nums[n - 1] - nums[k];

    cout << result << endl;

    return 0;
}