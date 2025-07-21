#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        int d = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();
        if (c > d) swap(c, d); // Ensure c <= d
        long long result = sum[min(d, n)] - sum[max(c - 1, 0)];
        cout << result << '\n';
    }

    return 0;
}