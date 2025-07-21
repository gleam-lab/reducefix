#include <bits/stdc++.h>
using namespace std;

int n, q;
long long x[200005], p[200005], sum[2000005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    sort(x + 1, x + n + 1);  // Sort array x
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x;  // Find the first position >= L
        int r = upper_bound(x + 1, x + n + 1, R) - x - 1;  // Find the last position <= R and subtract 1
        cout << sum[r] - sum[l - 1] << endl;  // Output the sum for the range [l, r] in terms of p array indices
    }
    return 0;
}