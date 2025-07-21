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
        
        // Find lower bound (first x[i] >= l)
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        
        // Find upper bound (first x[i] > r)
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        
        // The valid range is [left, right-1]
        if (left <= right - 1) {
            cout << a[right - 1] - a[left - 1] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}