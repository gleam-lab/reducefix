#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007

ll exp(int i, bool parity, const vector<ll>& v, vector<vector<ll>>& dp) {
    if (i == v.size())
        return 0;

    if (dp[i][parity] != -1)
        return dp[i][parity];

    ll take = exp(i + 1, !parity, v, dp) + (parity ? v[i] : 2 * v[i]);
    ll leave = exp(i + 1, parity, v, dp);

    return dp[i][parity] = max(take, leave);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    cout << exp(0, true, v, dp) << '\n';
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--)
        solve();
    return 0;
}