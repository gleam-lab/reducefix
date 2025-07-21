#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r;
        auto it1 = lower_bound(x + 1, x + n + 1, l);
        auto it2 = upper_bound(x + 1, x + n + 1, r);
        cout << (*it2 - *it1 == 0 ? 0 : a[it2 - x] - a[it1 - x - 1]) << endl;
    }
    return 0;
}