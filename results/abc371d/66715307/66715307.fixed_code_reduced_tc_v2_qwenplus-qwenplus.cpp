#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + x[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        int right = upper_bound(x + 1, x + n + 1, r) - x - 1;
        if (left > right) cout << 0 << '\n';
        else cout << p[right] - p[left - 1] << '\n';
    }
    return 0;
}