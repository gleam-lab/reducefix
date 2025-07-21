#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        if (it_l == x + n + 1 || *it_l > r) --it_l;
        if (it_r == x + n + 1 || *it_r < l) --it_r;
        int idx_l = it_l - x, idx_r = it_r - x;
        cout << sum[idx_r] - sum[idx_l - 1] << '\n';
    }
    return 0;
}