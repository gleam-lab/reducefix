#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
int sum[2000005];

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
        l = lower_bound(x + 1, x + n + 1, l) - x - 1; // Off by one
        r = upper_bound(x + 1, x + n + 1, r) - x; // Off by one
        // Check if the range is valid
        if (l > r || r <= 0) {
            cout << 0 << endl;
        } else {
            cout << sum[r - 1] - sum[l - 1] << endl;
        }
    }
    return 0;
}