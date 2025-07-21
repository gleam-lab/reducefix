#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;

ll dp[N][2];

ll exp(int i, bool parity) {
    if (i == -1)
        return 0;

    if (dp[i][parity] != -1)
        return dp[i][parity];

    ll take = (parity ? v[i] : 2 * v[i]) + exp(i - 1, !parity);
    ll leave = exp(i - 1, parity);

    return dp[i][parity] = max(take, leave);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << exp(n - 1, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q = 1;
    //cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}