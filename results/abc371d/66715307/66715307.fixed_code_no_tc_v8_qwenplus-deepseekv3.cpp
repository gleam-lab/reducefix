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
        int l, r;
        cin >> l >> r;
        
        // Find first index where x[i] >= l (lower bound)
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x[mid] >= l) right = mid;
            else left = mid + 1;
        }
        int l1 = (x[left] >= l) ? left : n + 1;  // if not found
        
        // Find last index where x[i] <= r (upper bound)
        left = 1, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (x[mid] <= r) left = mid;
            else right = mid - 1;
        }
        int l2 = (x[left] <= r) ? left : 0;  // if not found
        
        if (l1 <= l2) cout << a[l2] - a[l1 - 1] << endl;
        else cout << 0 << endl;  // no elements in range
    }
    return 0;
}