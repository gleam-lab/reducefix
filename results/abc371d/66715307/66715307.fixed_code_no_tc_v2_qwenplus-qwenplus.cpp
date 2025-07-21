#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + x[i]; // Fix: prefix sum of positions is not needed, probably misused variable
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1]; // Fix: cumulative sum of values
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Binary search to find lower bound index
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        int right = upper_bound(x + 1, x + n + 1, r) - x - 1;
        if (left > right)
            cout << 0 << endl;
        else
            cout << a[right] - a[left - 1] << endl;
    }

    return 0;
}