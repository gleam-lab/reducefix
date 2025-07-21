#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i]; // Accumulate prefix sum of p
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r; // Read the query range [l, r]
        // Find the lower bound index l1 in x that is greater than or equal to l
        int l1 = lower_bound(x + 1, x + n + 1, l) - x; // Use lower_bound from <algorithm>
        // Find the lower bound index l2 in x that is less than or equal to r (Note: l2 is one-based)
        auto l2 = upper_bound(x + 1, x + n + 1, r) - x - 1; // Use upper_bound from <algorithm>
        // Check if l2 is within valid bounds (it should be greater than or equal to l1)
        if (l2 >= l1) {
            cout << a[l2] - a[l1 - 1] << endl; // Output the difference in prefix sums
        } else {
            cout << "0" << endl; // If there's no overlap, output 0
        }
    }
    return 0;
}