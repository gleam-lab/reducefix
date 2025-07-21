#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2); // 1-based indexing
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
        long long L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L
        auto left = lower_bound(x.begin() + 1, x.begin() + n + 1, L);
        int l = left - x.begin();

        // Find the last index where x[i] <= R
        auto right = upper_bound(x.begin() + 1, x.begin() + n + 1, R);
        int r = (right - x.begin()) - 1;

        if (l <= r) {
            cout << prefix_sum[r] - prefix_sum[l - 1] << "\n";
        } else {
            cout << "0\n"; // No elements in range
        }
    }

    return 0;
}