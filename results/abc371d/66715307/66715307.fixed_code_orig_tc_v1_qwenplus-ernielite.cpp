#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], q, a[200050];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i]; // Accumulate prefix sum of p[]
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r; // Read query range (l, r)
        // Binary search to find the left index (l1) for 'l' in x[] array
        int l1 = 1, r1 = n, l2 = 1, r2 = n; // Initialize l2 and r2 to same bounds as l1 and r1 for consistency (though not strictly necessary)
        while (l1 < r1) { // Find left index for 'l' in sorted x[] array
            int mid = l1 + (r1 - l1) / 2; // Use this instead of l1 + r1 to avoid overflow for large n values.
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        // Binary search to find the right index (r2) for 'r' in x[] array (Note: this part is not strictly necessary as we only need l2 for output)
        while (l2 < r2) { // Find right index for 'r' in sorted x[] array for consistency check later if needed.
            int mid = l2 + (r2 - l2) / 2; // Same as above for avoiding overflow.
            if (x[mid] <= r) r2 = mid; // Correct condition here. We want to find the rightmost index that is less than or equal to 'r'.
            else l2 = mid + 1; // Continue searching.
        }
        // Output the result using the correct indices (l1 and l2) to calculate the range of a[] covered by the query range (l, r).
        cout << a[l2 - 1] - a[l1 - 1] << endl; // Subtracting 1 from indices as arrays are 0-indexed in our code. Also, use a[l2 - 1] instead of a[l2] for correct output.
    }
    return 0;
}