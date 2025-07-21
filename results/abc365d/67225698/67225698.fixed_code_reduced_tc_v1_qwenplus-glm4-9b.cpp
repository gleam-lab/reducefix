#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define fast_io() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

#define ll long long
#define mod 998244353

const ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    cout << ans << "\n";
}

int main() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}