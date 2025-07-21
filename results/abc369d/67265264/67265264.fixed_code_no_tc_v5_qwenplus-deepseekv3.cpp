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
ll dp[N][2]; // dp[i][0] = not taken previous, dp[i][1] = taken previous

ll exp(int i = 0, bool taken_prev = false) {
    if (i == n)
        return 0;

    if (~dp[i][taken_prev])
        return dp[i][taken_prev];

    ll leave = exp(i + 1, false);
    ll take = 0;
    
    if (!taken_prev) {
        take = exp(i + 1, true) + v[i];
    } else {
        take = exp(i + 1, true) + 2 * v[i];
    }

    return dp[i][taken_prev] = max(take, leave);
}

void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << exp() << "\n";
}

int main() {
    Youssef
    int q = 1;
    //cin >> q;
    while (q--)
        solve();
    return 0;
}