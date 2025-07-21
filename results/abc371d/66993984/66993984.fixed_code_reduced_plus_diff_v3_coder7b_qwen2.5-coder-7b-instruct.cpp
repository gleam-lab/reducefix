#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1);
    map<int, long long> prefix_sum;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x.begin(), x.end(), L) - x.begin();
        int d = upper_bound(x.begin(), x.end(), R) - x.begin();

        cout << prefix_sum[d - 1] - prefix_sum[c - 1] << '\n';
    }

    return 0;
}