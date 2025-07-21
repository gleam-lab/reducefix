#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sliding window to find minimum range after removing K elements
    int min_diff = INT_MAX;
    int window_size = n - k;

    // We'll consider all subarrays of size `window_size` in the original array
    // Each such subarray corresponds to removing exactly K elements
    for (int i = 0; i + window_size <= n; ++i) {
        int current_min = A[i];
        int current_max = A[i];
        for (int j = i; j < i + window_size; ++j) {
            current_min = min(current_min, A[j]);
            current_max = max(current_max, A[j]);
        }
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff << endl;
    return 0;
}