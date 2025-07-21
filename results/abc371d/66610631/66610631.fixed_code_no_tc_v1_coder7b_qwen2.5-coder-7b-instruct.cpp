#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 2e5 + 7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n;
    vector<ll> x(n + 1, 0), p(n + 1, 0), sum(n + 1, 0);
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
        auto l_it = lower_bound(x.begin() + 1, x.end(), l);
        auto r_it = upper_bound(x.begin() + 1, x.end(), r);
        if (r_it == x.end() && l_it == x.begin() + 1) cout << sum[n] << '\n';
        else if (r_it == x.end()) cout << sum[n] - sum[l_it - x.begin()] << '\n';
        else if (l_it == x.begin() + 1) cout << sum[r_it - x.begin() - 1] << '\n';
        else cout << sum[r_it - x.begin() - 1] - sum[l_it - x.begin()] << '\n';
    }
    return 0;
}