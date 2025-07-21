#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // Initial maximum and minimum values
    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    int initial_diff = max_val - min_val;

    // We need to consider the impact of removing up to k elements
    int min_diff = initial_diff; // Start with the initial difference
    int l = 0, r = 0;
    int count = 0;
    int max_in_window = INT_MIN, min_in_window = INT_MAX;

    while (r < n) {
        // Expand the window until we have k elements
        if (count < k) {
            max_in_window = max(max_in_window, a[r]);
            min_in_window = min(min_in_window, a[r]);
            r++;
            count++;
        } else {
            // We have k elements in the window; check the difference
            min_diff = min(min_diff, max_in_window - min_in_window);

            // Shrink from left
            max_in_window = max(max_in_window, a[l]);
            min_in_window = min(min_in_window, a[l]);
            l++;
            count--;
        }
    }

    cout << min_diff << endl;
    return 0;
}