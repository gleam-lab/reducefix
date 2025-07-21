#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN], sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        cout << sum[r - 1] - sum[l - 1] << '\n';
    }

    return 0;
}