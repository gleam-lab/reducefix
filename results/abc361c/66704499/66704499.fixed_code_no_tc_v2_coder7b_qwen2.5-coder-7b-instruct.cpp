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

    // After removing K elements, we will have (n - K) elements left.
    // The minimum possible difference will be between the smallest (nums[K]) and largest (nums[n-K-1]) elements of the remaining sequence.
    cout << nums[n - k - 1] - nums[k] << endl;

    return 0;
}