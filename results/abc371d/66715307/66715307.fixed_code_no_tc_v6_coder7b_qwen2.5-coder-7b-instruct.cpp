#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first index where x[index] >= l
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        int idx_l = it_l - x;
        
        // Find the first index where x[index] > r
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        int idx_r = it_r - x;
        
        cout << a[idx_r - 1] - a[idx_l - 2] << endl;
    }

    return 0;
}