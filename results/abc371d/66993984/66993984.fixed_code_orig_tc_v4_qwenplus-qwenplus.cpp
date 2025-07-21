#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2);  // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<long long> p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Precompute prefix sums of p
    vector<long long> sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L using lower_bound
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();

        // Find first index where x[i] > R using upper_bound
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();

        // The number of elements in [L, R] is (right - 1) - left + 1 ?
        // But we need to compute sum[p[i]] from left to (right - 1)
        if (left == n + 1 || x[left] > R) {
            cout << 0 << '\n';
        } else {
            cout << sum[right - 1] - sum[left - 1] << '\n';
        }
    }

    return 0;
}