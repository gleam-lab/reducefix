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
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        cout << a[right] - a[left - 1] << endl;
    }
    return 0;
}