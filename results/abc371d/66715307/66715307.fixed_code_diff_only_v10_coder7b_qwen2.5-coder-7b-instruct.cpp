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
        int pos_l = lower_bound(x + 1, x + n + 1, l) - x;
        int pos_r = upper_bound(x + 1, x + n + 1, r) - x - 1;
        cout << a[pos_r] - a[max(0, pos_l - 1)] << endl;
    }

    return 0;
}