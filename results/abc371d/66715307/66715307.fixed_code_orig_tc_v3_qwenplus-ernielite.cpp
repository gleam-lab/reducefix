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
        int l, r; cin >> l >> r; // Read range [l, r] for each query
        // Binary search for left index (l1) of l in x[] (to find cumulative sum prefix)
        int l1 = 1, r1 = n, l2 = 1, r2 = n; // Initialize indices for binary search
        while (l1 < r1) { // Correct condition to find l1 (left index)
            int mid = l1 + (r1 - l1) / 2; // Correct calculation of mid for binary search
            if (x[mid] >= l) r1 = mid; // Use correct condition to update r1 for l1 binary search
            else l1 = mid + 1; // Update l1 accordingly if x[mid] is less than l
        }
        while (l2 < r2) { // Similarly, correct binary search loop for l2 (right index)
            int mid = l2 + (r2 - l2 + 1) / 2; // Increment by 1 in case of using l2 as base index in a[] prefix sum array
            if (x[mid] <= r) l2 = mid; // Use correct condition to update l2 for a[] prefix sum calculation (i.e., finding cumulative sum within [l, r])
            else r2 = mid - 1; // Update r2 accordingly if x[mid] is greater than r (which is our target value)
        }
        // Compute the cumulative sum between l1 and l2 using a[] prefix sum array (note: we subtract 1 from l2 as a[] is zero-indexed)
        cout << a[l2 - 1] - a[l1 - 1] << endl; // Output the result for each query
    }
    return 0;
}