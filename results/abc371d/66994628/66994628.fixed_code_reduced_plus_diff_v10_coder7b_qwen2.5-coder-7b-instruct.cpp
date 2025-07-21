#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1), sum(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x.begin(), x.end(), l);
        auto it_r = upper_bound(x.begin(), x.end(), r);
        int idx_l = it_l - x.begin();
        int idx_r = it_r - x.begin();

        long long result = sum[idx_r - 1] - sum[idx_l - 1];
        cout << result << endl;
    }

    return 0;
}