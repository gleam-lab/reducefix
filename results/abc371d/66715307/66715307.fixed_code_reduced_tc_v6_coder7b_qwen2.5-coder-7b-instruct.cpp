#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (x[i] >= l && x[i] <= r) {
                sum += p[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}