#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array
    sort(a.begin(), a.end());

    // Initialize pointers and variables
    int left = 0, right = 0;
    int min_diff = INT_MAX;

    // Use a sliding window to find the optimal removal of K elements
    while (right + 1 < n) {
        // Try to expand the window to the right
        right++;
        // While the difference between max and min within the window is greater than
        // the difference between max and min of the current window, move the left pointer
        while (a[right] - a[left] > a[right - 1] - a[left + 1]) {
            left++;
        }
        // Update the minimum difference found so far
        min_diff = min(min_diff, a[right] - a[left]);
        // If we have removed enough elements, stop
        if (right - left + 1 == n - k) {
            break;
        }
    }

    // Output the result
    cout << min_diff << endl;

    return 0;
}