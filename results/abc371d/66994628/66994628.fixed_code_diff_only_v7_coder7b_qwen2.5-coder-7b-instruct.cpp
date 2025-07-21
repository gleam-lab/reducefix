#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
int sum[200005]; // Adjust size to include 0-based indexing

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Corrected index access
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = lower_bound(x + 1, x + n + 1, l) - x; // Corrected array bounds
        r = upper_bound(x + 1, x + n + 1, r) - x; // Corrected array bounds
        if (l > r || l == 0) continue; // Handle invalid range
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
    return 0;
}