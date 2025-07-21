#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005];

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
        int low = lower_bound(x + 1, x + n + 1, l) - x;
        int high = upper_bound(x + 1, x + n + 1, r) - x;
        // Ensure the bounds are within the valid range
        low = max(low, 1);
        high = min(high, n);
        cout << sum[high] - sum[low - 1] << endl;
    }
    return 0;
}