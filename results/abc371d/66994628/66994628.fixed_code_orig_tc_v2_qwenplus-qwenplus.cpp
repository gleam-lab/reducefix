#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2);  // 1-based indexing
    vector<long long> p(n + 2);
    vector<long long> prefix_sum(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;

    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Find first index where x[i] >= l using lower_bound
        auto left = lower_bound(x.begin() + 1, x.begin() + n + 1, l);
        int left_idx = left - x.begin();

        // Find last index where x[i] <= r using upper_bound
        auto right = upper_bound(x.begin() + 1, x.begin() + n + 1, r);
        int right_idx = right - x.begin() - 1;

        if (left_idx > right_idx) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[right_idx] - prefix_sum[left_idx - 1] << '\n';
        }
    }

    return 0;
}