#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2); // Extra space to avoid issues with upper_bound
    vector<long long> p(n + 2);
    vector<long long> prefix_sum(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Build prefix sum
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Find first index where x[i] >= l
        int left_idx = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();

        // Find first index where x[i] > r
        int right_idx = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin();

        // Adjust for prefix sum
        if (left_idx > n || x[left_idx] > r) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[right_idx - 1] - prefix_sum[left_idx - 1] << '\n';
        }
    }

    return 0;
}