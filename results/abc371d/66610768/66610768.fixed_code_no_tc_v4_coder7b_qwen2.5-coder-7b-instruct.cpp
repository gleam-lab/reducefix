#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 2e5 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<ll> x(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        prefix_sum[i] = prefix_sum[i - 1] + p[i];

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x.begin() + 1, x.end(), l);
        auto it_r = upper_bound(x.begin() + 1, x.end(), r);
        if (it_l == x.end()) continue; // Handle out-of-bound case
        int idx_l = distance(x.begin(), it_l);
        int idx_r = distance(x.begin(), it_r);
        if (x[idx_r - 1] > r) --idx_r; // Adjust index if right bound is not included

        ll result = prefix_sum[idx_r - 1] - prefix_sum[idx_l - 1];
        cout << result << '\n';
    }

    return 0;
}