#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

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
        // Adjust indices to be zero-based for lower_bound and upper_bound
        l = lower_bound(x + 1, x + n + 1, l) - x;
        r = upper_bound(x + 1, x + n + 1, r) - x;
        // Since upper_bound points to the first element greater than r,
        // we need to subtract 1 from r if it is within bounds
        if (r <= n) r--;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}