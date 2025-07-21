#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // If we can remove all but one element, the difference will be zero
    if (n - k == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Sort the array to easily find the smallest and largest elements after removal
    sort(a.begin(), a.end());

    // Initialize the minimum difference to a large number
    int min_diff = INT_MAX;

    // Iterate through possible starting points for removing k elements
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the largest and smallest elements in the remaining part
        int diff = a[i + k - 1] - a[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }

    // Output the result
    cout << min_diff << endl;
    return 0;
}