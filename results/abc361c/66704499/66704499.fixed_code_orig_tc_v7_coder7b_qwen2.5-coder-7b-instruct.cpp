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

    // Remove the smallest K/2 elements and the largest K/2 elements
    int min_val = nums[K / 2];
    int max_val = nums[n - K / 2 - 1];

    cout << max_val - min_val << endl;

    return 0;
}