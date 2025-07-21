#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int> prefix_sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Adjusting indices to match zero-based indexing of map
        auto it_l = prefix_sum.lower_bound(l);
        auto it_r = prefix_sum.upper_bound(r);

        if (it_l == prefix_sum.end() || it_r == prefix_sum.begin()) {
            cout << 0 << endl; // No valid range found
        } else {
            --it_r; // Correcting upper bound to include the last element within the range
            cout << it_r->second - it_l->second << endl;
        }
    }
    return 0;
}