#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005];
long long sum[200005]; // Use long long to avoid overflow

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
        // Ensure l and r are within bounds
        if (l > r || l < 1 || r > n) {
            cout << 0 << endl; // Edge case where there is no valid range
        } else {
            cout << sum[r - 1] - sum[l - 1] << endl;
        }
    }
    return 0;
}