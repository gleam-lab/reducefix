#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    // Correct the prefix sum calculation by summing x[i] instead of p[i]
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + x[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Adjust bounds l and r for 0-based index
        l = max(1, l);
        r = min(n, r);
        // Use the prefix sums to answer the query
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}