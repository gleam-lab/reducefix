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

ll exp(int i, bool parity) {
    if (i == n)
        return 0;

    if (dp[i][parity] != -1)
        return dp[i][parity];

    // Either take the current element and flip parity, or skip it
    ll take = (parity ? v[i] : -v[i]) + exp(i + 1, !parity);
    ll skip = exp(i + 1, parity);

    return dp[i][parity] = max(take, skip);
}

void solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    // Initialize dp table with -infinity or appropriate minimum
    memset(dp, -1, sizeof dp);

    // Start with parity 1 (odd index assumed as per 0-based starting point)
    cout << exp(0, 1);
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--)
        solve();
    return 0;
}