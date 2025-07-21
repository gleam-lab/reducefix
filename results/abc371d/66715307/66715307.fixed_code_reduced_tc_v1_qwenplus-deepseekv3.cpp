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
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int l1 = 1, r1 = n, ans1 = n + 1;
        while (l1 <= r1) {
            int mid = (l1 + r1) / 2;
            if (x[mid] >= l) {
                ans1 = mid;
                r1 = mid - 1;
            } else {
                l1 = mid + 1;
            }
        }
        int l2 = 1, r2 = n, ans2 = 0;
        while (l2 <= r2) {
            int mid = (l2 + r2) / 2;
            if (x[mid] <= r) {
                ans2 = mid;
                l2 = mid + 1;
            } else {
                r2 = mid - 1;
            }
        }
        if (ans1 > ans2) {
            cout << 0 << endl;
        } else {
            cout << a[ans2] - a[ans1 - 1] << endl;
        }
    }
    return 0;
}