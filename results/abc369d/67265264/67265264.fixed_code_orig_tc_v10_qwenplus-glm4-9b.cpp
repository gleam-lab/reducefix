#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

ll dp[1e5 + 5][2];

ll exp(int i, bool parity) {
    if (i == n)
        return 0;
    
    if (dp[i][parity] != -1)
        return dp[i][parity];

    ll take = exp(i + 1, !parity) + (parity ? v[i] : 2 * v[i]);
    ll leave = exp(i + 1, parity);

    return dp[i][parity] = max(take, leave);
}

void solve() {
    cin >> n;
    vector<ll> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << exp(0, 1) << endl; // Starting from index 0 with parity 1
}

int main() {
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}