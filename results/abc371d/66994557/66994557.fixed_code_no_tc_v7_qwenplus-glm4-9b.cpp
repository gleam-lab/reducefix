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
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        if (l > r) { // Ensure we are within the bounds
            cout << 0 << endl; // Edge case where no elements are in the range
        } else {
            cout << sum[r - 1] - sum[l - 1] << endl; // Calculate the prefix sum difference
        }
    }
    return 0;
}