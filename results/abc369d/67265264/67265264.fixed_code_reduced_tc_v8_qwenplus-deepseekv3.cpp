#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n;
vector<ll> v;
ll dp[N][2];

ll exp(int i = 0, bool parity = false) {
    if (i == n)
        return 0;
    
    if (dp[i][parity] != -1)
        return dp[i][parity];
    
    ll take = exp(i + 1, !parity) + (parity ? 2 * v[i] : v[i]);
    ll leave = exp(i + 1, parity);
    
    return dp[i][parity] = max(take, leave);
}

void solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    memset(dp, -1, sizeof dp);
    cout << exp() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q = 1;
    while (q--)
        solve();
    
    return 0;
}