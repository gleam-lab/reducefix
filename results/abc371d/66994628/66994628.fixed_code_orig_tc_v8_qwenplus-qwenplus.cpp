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
    
    vector<long long> p(n + 2), prefix_sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Binary search to find the first index where x[i] >= l
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();
        // Binary search to find the last index where x[i] <= r
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin() - 1;

        if (left > right) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[right] - prefix_sum[left - 1] << '\n';
        }
    }

    return 0;
}