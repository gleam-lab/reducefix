#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
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
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        int idx_l = it_l - x, idx_r = it_r - x;
        if (idx_l > idx_r) --idx_l;
        cout << sum[idx_r] - sum[idx_l - 1] << '\n';
    }

    return 0;
}