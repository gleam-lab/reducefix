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
        int l1 = 1, r1 = n, l2 = 1, r2 = n;
        while (l1 < r1) {
            int mid = l1 + (r1 - l1) / 2;
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        while (l2 < r2) {
            int mid = l2 + (r2 - l2 + 1) / 2;
            if (x[mid] <= r) l2 = mid;
            else r2 = mid - 1;
        }
        // Ensure the bounds are within the array limits
        l1 = max(l1, 1);  // Handle the case where l1 is 0 by setting it to 1
        r2 = min(r2, n);  // Ensure we do not go out of array bounds
        cout << a[r2] - (l1 == 1 ? 0 : a[l1 - 1]) << endl;
    }
    return 0;
}