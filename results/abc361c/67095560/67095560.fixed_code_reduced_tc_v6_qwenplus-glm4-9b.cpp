#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Create a vector to store the maximum values from the sliding window
    vector<int> max_values(k);
    int window_sum = 0;
    int window_max = -1e9; // Start with a very small value to prevent overflow

    // Calculate initial window sum and max value
    for (int i = 0; i < k; i++) {
        window_sum += a[i];
        window_max = max(window_max, a[i]);
    }
    max_values[0] = window_max;
    cout << window_sum - window_max;

    // Slide the window
    for (int i = 1; i < n - k + 1; i++) {
        window_sum -= a[i - 1];
        window_sum += a[i + k - 1];
        window_max = window_max - a[i - 1] + a[i + k - 1];
        max_values[i] = window_max;
        cout << " " << window_sum - window_max;
    }

    // Output the minimum possible value
    cout << endl << *min_element(max_values.begin(), max_values.end());
}

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}