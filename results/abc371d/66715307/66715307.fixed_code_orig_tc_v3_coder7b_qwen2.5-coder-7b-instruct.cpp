#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        auto it1 = lower_bound(x + 1, x + n + 1, l);
        auto it2 = upper_bound(x + 1, x + n + 1, r);
        int idx1 = it1 - x, idx2 = it2 - x - 1;
        if (idx1 > idx2) {
            cout << "0\n";
        } else {
            cout << a[idx2] - a[idx1 - 1] << '\n';
        }
    }

    return 0;
}