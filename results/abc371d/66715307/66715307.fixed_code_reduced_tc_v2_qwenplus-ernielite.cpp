#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i]; // Calculate prefix sum
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r; // Read the range [l, r]
        // Find the indices in a[] that correspond to the range in x[] using binary search
        auto it_l = lower_bound(x + 1, x + n + 1, l, greater<int>()); // Find index of l in x[] (using greater to find >= l)
        auto it_r = upper_bound(x + 1, x + n + 1, r); // Find index of r in x[] (exclusive)
        if (it_l == it_r) { // If l is not found in x[], or l and r are at the same position in x[]
            cout << "0\n"; // Output 0 since no valid range exists
        } else {
            // Calculate the difference in prefix sums between the two indices found in a[]
            cout << a[it_r - 1] - a[it_l - 1] << endl; // Subtracting 1 since we want to exclude the end points of the range in a[]
        }
    }
    return 0;
}