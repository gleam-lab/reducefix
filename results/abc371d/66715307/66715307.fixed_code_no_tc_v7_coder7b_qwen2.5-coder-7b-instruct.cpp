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
    while (q--) {
        int l, r; cin >> l >> r;
        int posL = lower_bound(x + 1, x + n + 1, l) - x;
        int posR = upper_bound(x + 1, x + n + 1, r) - x;
        cout << a[posR - 1] - a[posL - 2] << endl;
    }
    return 0;
}