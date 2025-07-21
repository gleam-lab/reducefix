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
        long long l, r;
        cin >> l >> r;

        // Find the first index where x[i] >= l using lower_bound
        int left = lower_bound(x.begin() + 1, x.end(), l) - x.begin();

        // Find the first index where x[i] > r using upper_bound
        int right = upper_bound(x.begin() + 1, x.end(), r) - x.begin() - 1;

        if (left > right) {
            cout << 0 << "\n";
        } else {
            cout << prefix_sum[right] - prefix_sum[left - 1] << "\n";
        }
    }

    return 0;
}