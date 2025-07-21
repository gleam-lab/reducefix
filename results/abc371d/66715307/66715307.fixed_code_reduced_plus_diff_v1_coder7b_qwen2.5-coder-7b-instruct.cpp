#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int l1 = 1, r1 = n, l2 = 1, r2 = n;
        while (l1 < r1) {
            int mid = l1 + r1 >> 1;
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        while (l2 < r2) {
            int mid = l2 + r2 + 1 >> 1;
            if (x[mid] <= r) l2 = mid;
            else r2 = mid - 1;
        }
        cout << a[l2] - a[l1 - 1] << '\n';
    }

    return 0;
}