#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005], sum[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i > 0) sum[i] = sum[i - 1] + p[i];
        else sum[i] = p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x;
        int r = upper_bound(x, x + n, R) - x;
        if (l > r - 1) cout << 0 << endl; // To handle cases where R < L
        else cout << sum[r - 1] - sum[l - 1] << endl;
    }
    return 0;
}