#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

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
        cout << a[l2] - a[l1 - 1] << endl;
    }
    return 0;
}