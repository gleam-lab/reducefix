#include <bits/stdc++.h>
using namespace std;

int n, q;
long long x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i]; // sum[i+1] to keep sum[0] as 0 (for convenience)
    }
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x, x + n, l) - x;
        auto it_r = upper_bound(x, x + n, r) - x;
        // Since sum is 1-based relative to p (sum[0] is unused), adjust indices accordingly
        cout << sum[it_r] - sum[it_l] << endl;
    }
    return 0;
}