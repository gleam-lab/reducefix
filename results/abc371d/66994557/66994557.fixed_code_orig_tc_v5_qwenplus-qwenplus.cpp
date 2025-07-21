#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n, q;
ll x[MAXN], p[MAXN];
ll prefix_sum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Build prefix sum array
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        ll L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L
        int left = lower_bound(x + 1, x + n + 1, L) - x;

        // Find the last index where x[i] <= R
        int right = upper_bound(x + 1, x + n + 1, R) - x - 1;

        if (left > right) {
            cout << 0 << "\n";
        } else {
            cout << prefix_sum[right] - prefix_sum[left - 1] << "\n";
        }
    }

    return 0;
}