#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
long long x[MAXN], a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        a[i] = a[i - 1] + x[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto lb = lower_bound(x + 1, x + n + 1, l);
        auto ub = upper_bound(x + 1, x + n + 1, r);
        if (lb == ub) {
            cout << 0 << endl;
        } else {
            int l1 = lb - x, r1 = ub - x - 1;
            cout << a[r1] - a[l1 - 1] << endl;
        }
    }

    return 0;
}