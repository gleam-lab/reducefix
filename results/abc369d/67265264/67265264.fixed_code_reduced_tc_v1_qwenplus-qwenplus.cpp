#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;
int n;
vector<ll> v;
ll dp[N][2];

ll exp(int i = 0, bool parity = 0) { // Fixed default parity to start from even (0)

    if (i == n)
        return 0;

    if (~dp[i][parity])
        return dp[i][parity];

    // Take current element: switch parity and apply multiplier
    ll take = exp(i + 1, !parity) + (parity ? 2 * v[i] : v[i]);
    // Leave current element: keep current parity
    ll leave = exp(i + 1, parity);

    return dp[i][parity] = max(take, leave);
}

void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << exp();
}

int main() {
    Youssef
    int q = 1;
    //cin>>q;
    while (q--)
        solve();
    return 0;
}