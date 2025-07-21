#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find the minimum and maximum differences
    sort(a.begin(), a.end());

    // Initialize variables to store the minimum difference found
    long long min_diff = LLONG_MAX;

    // Iterate through possible positions to split the array into two parts
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum values in the resulting arrays
        long long diff = a[i + k - 1] - a[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }

    // Output the minimum difference
    cout << min_diff << endl;

    return 0;
}