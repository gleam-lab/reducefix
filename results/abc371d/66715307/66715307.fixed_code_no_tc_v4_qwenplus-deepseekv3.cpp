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
        int l, r;
        cin >> l >> r;
        
        // Find the first index where x[index] >= l
        int l1 = 1, r1 = n;
        while (l1 <= r1) {
            int mid = (l1 + r1) / 2;
            if (x[mid] >= l) r1 = mid - 1;
            else l1 = mid + 1;
        }
        // l1 is the first index where x[l1] >= l
        
        // Find the last index where x[index] <= r
        int l2 = 1, r2 = n;
        while (l2 <= r2) {
            int mid = (l2 + r2) / 2;
            if (x[mid] <= r) l2 = mid + 1;
            else r2 = mid - 1;
        }
        // r2 is the last index where x[r2] <= r
        
        if (l1 > n || r2 < 1 || l1 > r2) {
            cout << 0 << endl;
        } else {
            cout << a[r2] - a[l1 - 1] << endl;
        }
    }
    return 0;
}