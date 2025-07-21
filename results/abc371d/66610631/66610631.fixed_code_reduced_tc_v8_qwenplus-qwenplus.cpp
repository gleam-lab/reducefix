#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1), prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }

    cin >> m;

    while (m--) {
        ll l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l
        auto left_it = lower_bound(a.begin() + 1, a.end(), l);
        int left_idx = left_it - a.begin();

        // Find first index where a[i] > r
        auto right_it = upper_bound(a.begin() + 1, a.end(), r);
        int right_idx = right_it - a.begin() - 1;

        if (right_idx < left_idx) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[right_idx] - prefix_sum[left_idx - 1] << '\n';
        }
    }

    return 0;
}