#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1), sum(n + 2);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Adjusting indices to be zero-based for lower_bound and upper_bound
        auto it_l = lower_bound(x.begin(), x.end(), l) - x.begin();
        auto it_r = upper_bound(x.begin(), x.end(), r) - x.begin();

        if (it_l == n && x[it_l] < l) {
            ++it_l;
        }
        if (it_r == n && x[it_r] > r) {
            --it_r;
        }

        if (it_l <= it_r) {
            cout << sum[it_r] - sum[it_l - 1] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}