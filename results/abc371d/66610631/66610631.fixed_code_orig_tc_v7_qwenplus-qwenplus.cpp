#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 2), b(n + 2), prefix_sum(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }

    int m;
    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find first index in a >= l using lower_bound
        auto left = lower_bound(a.begin() + 1, a.end(), l);
        int left_idx = (left == a.end()) ? n + 1 : (left - a.begin());

        // Find first index in a > r using upper_bound
        auto right = upper_bound(a.begin() + 1, a.end(), r);
        int right_idx = (right == a.begin()) ? 0 : (right - a.begin() - 1);

        if (right_idx >= left_idx) {
            cout << prefix_sum[right_idx] - prefix_sum[left_idx - 1] << "\n";
        } else {
            cout << "0\n"; // No elements in range [l, r]
        }
    }

    return 0;
}