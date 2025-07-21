#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Sort the array
    sort(num.begin(), num.end());

    // Initialize the minimum difference with a large number
    int min_diff = INT_MAX;

    // Iterate over all possible subarrays of size (N - K)
    for (int i = 0; i <= n - k; i++) {
        // Calculate the difference between the maximum and minimum values in the current subarray
        int diff = num[i + k - 1] - num[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }

    // Output the minimum difference
    cout << min_diff << endl;

    return 0;
}