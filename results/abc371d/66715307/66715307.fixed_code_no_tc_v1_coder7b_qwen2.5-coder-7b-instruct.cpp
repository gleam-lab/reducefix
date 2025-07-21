#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        int idx_l = it_l - x, idx_r = it_r - x;
        if (idx_l > idx_r) idx_l--;
        cout << a[idx_r] - a[idx_l - 1] << endl;
    }

    return 0;
}