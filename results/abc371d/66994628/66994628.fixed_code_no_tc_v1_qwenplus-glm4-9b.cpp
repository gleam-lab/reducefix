#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        int lb = lower_bound(x + 1, x + n + 1, l) - x;
        int ub = upper_bound(x + 1, x + n + 1, r) - x;
        if (lb == ub) {
            cout << 0 << endl;
        } else {
            cout << sum[ub - 1] - sum[lb - 1] << endl;
        }
    }
    return 0;
}