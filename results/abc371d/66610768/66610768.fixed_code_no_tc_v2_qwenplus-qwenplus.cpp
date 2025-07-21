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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    // Prefix sum of b values
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find left and right indices in a using binary search
        int left = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        int right = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1;

        if (left > right) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[right] - prefix_sum[left - 1] << '\n';
        }
    }

    return 0;
}