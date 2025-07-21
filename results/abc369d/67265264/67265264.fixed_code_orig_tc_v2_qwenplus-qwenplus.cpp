#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const int N = 2e5 + 5;
int n;
vector<ll> v;
ll dp[N][2];

ll solve(int i, bool parity) {
    if (i == n)
        return 0;

    if (dp[i][parity] != -1)
        return dp[i][parity];

    ll take = solve(i + 1, !parity) + (parity ? v[i] : 2 * v[i]);
    ll leave = solve(i + 1, parity);

    return dp[i][parity] = max(take, leave);
}

int main() {
    Youssef
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1) << endl;

    return 0;
}