#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        p[i] = x[i];  // Store original positions in p
    }

    // Build prefix sum of p values
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i-1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Find leftmost index where x[i] >= l using binary search
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x[mid] >= l) right = mid;
            else left = mid + 1;
        }
        int left_idx = left;

        // If all elements are less than l, output 0
        if (x[left_idx] < l) {
            cout << 0 << endl;
            continue;
        }

        // Find rightmost index where x[i] <= r using binary search
        left = 1, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (x[mid] <= r) left = mid;
            else right = mid - 1;
        }
        int right_idx = left;

        // If valid range found
        if (right_idx >= left_idx && x[right_idx] <= r) {
            cout << a[right_idx] - a[left_idx - 1] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}