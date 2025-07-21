#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[200005];

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
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x - 1; // Subtract 1 to convert to 0-based index
        int r = upper_bound(x + 1, x + n + 1, R) - x; // Include R in the range
        if (l > 0) l--; // Adjust l to be zero-based and within bounds
        cout << sum[r - 1] - sum[l] << endl; // Adjust index for sum array
    }
    return 0;
}