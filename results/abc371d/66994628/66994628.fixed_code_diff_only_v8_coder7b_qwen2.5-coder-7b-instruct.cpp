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
        // Adjusting indices to be zero-based as lower_bound and upper_bound expect them to be
        l = lower_bound(x + 1, x + n + 1, l) - x;
        r = upper_bound(x + 1, x + n + 1, r) - x;
        if (l <= r && r <= n) { // Check if the range is valid
            cout << sum[r] - sum[l - 1] << endl; // Correctly output the difference
        } else {
            cout << "Invalid range" << endl; // Handle invalid ranges appropriately
        }
    }
    return 0;
}