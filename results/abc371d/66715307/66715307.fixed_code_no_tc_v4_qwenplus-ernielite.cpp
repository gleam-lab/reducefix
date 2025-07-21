#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i]; // Calculate prefix sum of p
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int l1 = 1, r1 = n; // Binary search for l1 (lower bound)
        while (l1 < r1) {
            int mid = l1 + r1 + 1 >> 1; // Add 1 for integer overflow protection
            if (x[mid] < l) l1 = mid + 1; // Correct condition to move l1 up
            else r1 = mid; // Update r1 if x[mid] >= l
        }
        int l2 = 0, r2 = n - 1; // Initialize l2 to 0 for binary search (lower bound)
        while (l2 < r2) {
            int mid = l2 + r2 >> 1; // No need to add 1 here as we are not using mid+1 later
            if (x[mid] > r) l2 = mid + 1; // Update l2 if x[mid] > r
            else r2 = mid; // Update r2 if x[mid] <= r
        }
        // Output should be a sum of a prefix sum of p from a lower to upper bound.
        // Correct calculation is a[r2] - a[l1]. If l1 is equal to n+1, then use a[n].
        cout << (l1 == n + 1 ? a[n] : a[r2]) - a[l1 - 1] << endl; // Use 'a' only for l2 >= 0
    }
    return 0;
}