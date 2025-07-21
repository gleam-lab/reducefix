#include <bits/stdc++.h>
using namespace std;

#define Youssef ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;

ll dp[2];

ll exp(vector<ll>& v, int i = 0, bool parity = 1) {
    if (i == v.size())
        return 0;

    if (dp[parity] != -1)
        return dp[parity];

    ll take = exp(v, i + 1, !parity) + (parity ? v[i] : 2 * v[i]);
    ll leave = exp(v, i + 1, parity);

    dp[parity] = max(take, leave);
    return dp[parity];
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << exp(v) << '\n';
}

int main() {
    Youssef
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}