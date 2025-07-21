#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Adjusting indices to be zero-based as lower_bound and upper_bound functions work with zero-based arrays
        l = lower_bound(x + 1, x + n + 1, l) - x - 1;
        r = upper_bound(x + 1, x + n + 1, r) - x - 1;

        if (l >= 0 && r < n) {
            cout << sum[r] - sum[l] << endl;
        } else {
            cout << "Invalid range" << endl;
        }
    }

    return 0;
}