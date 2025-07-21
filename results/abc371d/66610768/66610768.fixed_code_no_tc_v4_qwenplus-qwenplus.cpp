#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> a(n + 1, 0), b(n + 1, 0);
    vector<ll> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find first index in a where a[i] >= l
        int left_idx = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        
        // Find first index in a where a[i] > r
        int right_idx = upper_bound(a.begin() + 1, a.end(), r) - a.begin();

        if (left_idx > n) {
            cout << 0 << '\n';
        } else {
            // Sum from left_idx to right_idx - 1
            cout << prefix_sum[right_idx - 1] - prefix_sum[left_idx - 1] << '\n';
        }
    }

    return 0;
}