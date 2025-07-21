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
        int l, r; cin >> l >> r; // Read query's left and right boundaries
        int l1 = 1, r1 = n; // Initialize binary search for left boundary of x[] array
        while (l1 < r1) { // Find left boundary in x[] where x >= l
            int mid = l1 + (r1 - l1) / 2; // Use (r1 - l1) / 2 to prevent overflow for large differences
            if (x[mid] >= l) r1 = mid - 1; // Update r1 to find correct left boundary
            else l1 = mid + 1;
        }
        // Find the index in a[] which is less than or equal to l1-1 (the previous element before the left boundary in x[])
        int idx_left = upper_bound(a, a + n, a[l1 - 1]) - a - 1; // Use upper_bound to find the index in a[] less than or equal to a[l1-1]
        // Calculate the range sum from a[] up to idx_left-1 (since we are looking for the sum before the left boundary)
        long long sum_range = a[idx_left] - (idx_left > 0 ? a[idx_left - 1] : 0); // Account for sum up to l-1 (if idx_left > 0) or 0 if idx_left is 0 (i.e., no previous element)
        // Now find the right boundary of query using similar binary search logic but searching for a value <= r
        int l2 = 1, r2 = n; // Initialize binary search for right boundary of x[] array
        while (l2 < r2) { // Find right boundary in x[] where x <= r
            int mid = l2 + (r2 - l2) / 2; // Use (r2 - l2) / 2 to prevent overflow for large differences
            if (x[mid] <= r) l2 = mid; // Update l2 to find correct right boundary (if not already found by l1's search)
            else r2 = mid - 1; // Search within narrowed range from right
        }
        // We have found the left and right boundaries, so we can output the range sum between them from a[] array.
        cout << sum_range << endl; // Output the range sum from before the left boundary to before the right boundary in a[] array.
    }
    return 0;
}