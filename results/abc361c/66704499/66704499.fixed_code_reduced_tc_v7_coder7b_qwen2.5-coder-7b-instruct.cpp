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

    // The minimum possible range is the difference between the (n-k)-th and k-th elements
    int min_range = nums[n - k] - nums[k - 1];

    cout << min_range << endl;

    return 0;
}