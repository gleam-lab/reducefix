#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005], sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Use binary search to find the correct indices in the prefix sum array
        auto l_bin = lower_bound(x + 1, x + n + 1, l);
        auto r_bin = upper_bound(x + 1, x + n + 1, r);

        // Since lower_bound returns an iterator to the first element >= l, 
        // and upper_bound returns an iterator to the first element > r,
        // we need to adjust the indices to use them correctly with the prefix sum array.
        // Also, handle the case where l is out of bounds to the left (i.e., l > x[n])
        auto l_idx = l_bin - (x + 1) + (l_bin == x + n + 1 ? 1 : 0);
        auto r_idx = r_bin - (x + 1) - (r_bin == x + n + 1 ? 0 : 1);

        // Output the difference between the prefix sums
        cout << sum[r_idx] - sum[l_idx - 1] << endl;
    }
    return 0;
}