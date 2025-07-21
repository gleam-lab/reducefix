#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1), sum(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = lower_bound(begin(x) + 1, end(x), l) - begin(x);
        r = upper_bound(begin(x) + 1, end(x), r) - begin(x);
        if (l > r) {
            cout << "0\n";
        } else {
            cout << sum[r - 1] - sum[l - 1] << '\n';
        }
    }

    return 0;
}