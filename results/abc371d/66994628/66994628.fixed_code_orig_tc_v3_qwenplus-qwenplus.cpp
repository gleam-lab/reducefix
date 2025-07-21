#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<long long> x(n + 2); // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<long long> p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<long long> sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Find first index where x[i] >= l using lower_bound
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();

        // Find first index where x[i] > r using upper_bound
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin();

        if (left < right) {
            cout << sum[right - 1] - sum[left - 1] << "\n";
        } else {
            cout << 0 << "\n"; // No elements in range
        }
    }

    return 0;
}