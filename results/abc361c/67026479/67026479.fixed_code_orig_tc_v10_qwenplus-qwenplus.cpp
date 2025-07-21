#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int m = n - k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // To store the minimum difference between max and min in any window of size m
    long long min_diff = numeric_limits<long long>::max();

    // Sliding window using multiset to maintain current window elements
    multiset<int> window;

    // Initialize the first window
    for (int i = 0; i < m; ++i) {
        window.insert(a[i]);
    }

    // Process the first window
    min_diff = min(min_diff, (long long)*window.rbegin() - *window.begin());

    // Slide the window
    for (int i = m; i < n; ++i) {
        // Remove the element going out of the window
        auto it = window.find(a[i - m]);
        if (it != window.end()) {
            window.erase(it);
        }
        // Insert the new element
        window.insert(a[i]);
        // Update the min difference
        min_diff = min(min_diff, (long long)*window.rbegin() - *window.begin());
    }

    cout << min_diff << endl;
}