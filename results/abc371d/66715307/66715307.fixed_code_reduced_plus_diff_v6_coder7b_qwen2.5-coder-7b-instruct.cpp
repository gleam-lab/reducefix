#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        if (l > r || l > x[n] || r < x[1]) {
            cout << 0 << endl;
            continue;
        }
        auto lb = lower_bound(x + 1, x + n + 1, l);
        auto ub = upper_bound(x + 1, x + n + 1, r);
        int l1 = lb - x, r1 = ub - x;
        cout << a[r1 - 1] - a[l1 - 2] << endl;
    }
    return 0;
}