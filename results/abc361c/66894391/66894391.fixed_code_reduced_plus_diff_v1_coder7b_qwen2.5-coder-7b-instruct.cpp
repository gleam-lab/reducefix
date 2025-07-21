#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // The minimum value will be the first element after removing k elements
    // The maximum value will be the (n-k-1)-th element after removing k elements
    int min_val = nums[k];
    int max_val = nums[n - k - 1];

    cout << max_val - min_val << endl;

    return 0;
}