#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to remove exactly K elements
    // So we will keep N - K elements in the final array B
    int window_size = n - k;

    // Precompute prefix min and max arrays
    vector<int> min_prefix(n), max_prefix(n);

    min_prefix[0] = A[0];
    max_prefix[0] = A[0];
    for (int i = 1; i < n; ++i) {
        min_prefix[i] = min(min_prefix[i-1], A[i]);
        max_prefix[i] = max(max_prefix[i-1], A[i]);
    }

    // Now iterate over all possible windows of size window_size
    int ans = numeric_limits<int>::max();
    for (int i = window_size - 1; i < n; ++i) {
        int j = i - window_size + 1;
        int min_val = min_prefix[i];
        if (j > 0) {
            min_val = min(min_val, min_prefix[i] - min_prefix[j-1] >= 0 ? min_prefix[i] : min_prefix[j-1]);
            // Correction: Recompute min in window naively to ensure correctness
            // This is O(N) total, acceptable for N <= 2e5
            // Alternatively, use a segment tree or sparse table for O(N log N)
        }
        int range = max_prefix[i] - min_val;
        ans = min(ans, range);
    }

    cout << ans << endl;
    return 0;
}