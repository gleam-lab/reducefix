#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        int l_pos = distance(x + 1, it_l), r_pos = distance(x + 1, it_r);
        if (it_r == x + n + 1 && r >= x[n]) --r_pos;
        cout << a[r_pos] - (l_pos > 0 ? a[l_pos - 1] : 0) << '\n';
    }

    return 0;
}