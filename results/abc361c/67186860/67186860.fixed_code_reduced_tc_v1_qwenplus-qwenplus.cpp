#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will maintain two multisets:
    // - removed: the K elements we have decided to remove
    // - remaining: the rest of the elements
    multiset<int> remaining, removed;

    // Initialize by removing the last K elements (arbitrary initial choice)
    for (int i = 0; i < n; ++i) {
        if (i < k) {
            removed.insert(A[i]);
        } else {
            remaining.insert(A[i]);
        }
    }

    long long res = LLONG_MAX;

    // Slide the window: try every possible partition of removing K elements
    // from any sliding window of size K in the array
    for (int i = 0; i <= n - k; ++i) {
        // Update result with current min and max in 'remaining'
        if (!remaining.empty()) {
            int curr_min = *remaining.begin();
            int curr_max = *remaining.rbegin();
            res = min(res, (long long)(curr_max - curr_min));
        }

        // Move one step forward if not at the end
        if (i + k < n) {
            int out_elem = A[i];         // Element leaving the removed set
            int in_elem = A[i + k];      // Element entering the removed set

            // Remove 'out_elem' from removed set
            auto it = removed.find(out_elem);
            if (it != removed.end()) {
                removed.erase(it);
            }

            // Add 'in_elem' into removed set
            removed.insert(in_elem);

            // Maintain the remaining set
            remaining.clear();
            for (int j = 0; j < n; ++j) {
                if (j <= i + k && j > i) continue; // Skip the new removed element
                if ((j <= i || j > i + k)) {
                    remaining.insert(A[j]);
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}