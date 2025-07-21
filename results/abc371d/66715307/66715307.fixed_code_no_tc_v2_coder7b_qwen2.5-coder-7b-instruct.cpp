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
        auto it1 = lower_bound(x + 1, x + n + 1, l);
        auto it2 = upper_bound(x + 1, x + n + 1, r);
        cout << a[it2 - x - 1] - a[it1 - x] << endl;
    }
    return 0;
}