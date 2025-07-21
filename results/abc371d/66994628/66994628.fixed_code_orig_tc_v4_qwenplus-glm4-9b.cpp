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
        sum[i] = sum[i - 1] + p[i - 1];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = lower_bound(x + 1, x + n + 1, l) - x - 1; // Adjust for 0-based index and subtract 1
        r = upper_bound(x + 1, x + n + 1, r) - x - 1; // Adjust for 0-based index and subtract 1
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}