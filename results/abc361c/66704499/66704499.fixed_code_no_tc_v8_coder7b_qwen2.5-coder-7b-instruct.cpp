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

    // After sorting, the best way to minimize the difference between max and min
    // is to keep the smallest N-K elements together.
    cout << nums[n - k - 1] - nums[k] << endl;

    return 0;
}