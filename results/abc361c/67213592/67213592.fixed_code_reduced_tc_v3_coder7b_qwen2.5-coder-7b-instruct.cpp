#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // Sort the array to facilitate finding the min and max in the sliding window
    sort(v.begin(), v.end());

    // Initialize the minimum difference to a large number
    long long min_diff = LLONG_MAX;

    // Slide the window of size N-K across the sorted array
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the max and min values in the current window
        long long diff = v[i + k - 1] - v[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }

    // Output the minimum difference
    cout << min_diff << endl;

    return 0;
}