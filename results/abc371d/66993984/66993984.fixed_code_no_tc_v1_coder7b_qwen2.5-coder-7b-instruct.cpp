#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n, q, x[maxn], p[maxn];
long long sum[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> p[i];
        if (i > 1) {
            sum[i] = sum[i - 1];
        }
        sum[i] += p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto itl = lower_bound(x, x + n + 1, l);
        auto itr = upper_bound(x, x + n + 1, r);
        int idxl = itl - x;
        int idxr = itr - x - 1;
        if (idxl == 0 && idxr == n) {
            cout << sum[n] << '\n';
        } else if (idxl == 0) {
            cout << sum[idxr] << '\n';
        } else if (idxr == n) {
            cout << sum[n] - sum[idxl - 1] << '\n';
        } else {
            cout << sum[idxr] - sum[idxl - 1] << '\n';
        }
    }

    return 0;
}