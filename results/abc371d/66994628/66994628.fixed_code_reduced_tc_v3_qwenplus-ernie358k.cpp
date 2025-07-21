#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1); // Use n+1 to avoid off-by-one errors easily
    vector<long long> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Use auto for iterators to avoid overflow issues with indexing
        auto it_l = lower_bound(x.begin() + 1, x.end(), l);
        auto it_r = upper_bound(x.begin() + 1, x.end(), r);

        int idx_l = it_l - x.begin();
        int idx_r = it_r - x.begin();

        // Ensure indices are within bounds
        if (idx_l > 0 && idx_r <= n) {
            cout << sum[idx_r - 1] - sum[idx_l - 1] << endl;
        } else {
            cout << 0 << endl; // If indices are out of bounds, return 0 or handle appropriately
        }
    }

    return 0;
}