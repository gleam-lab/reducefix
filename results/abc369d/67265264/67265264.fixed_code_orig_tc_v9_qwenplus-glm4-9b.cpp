#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Youssef ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;

ll dp[N][2]; // dp[i][0] for taking, dp[i][1] for not taking

ll exp(int i, bool parity, int n) {
    if (i == n)
        return 0;

    if (~dp[i][parity])
        return dp[i][parity];

    ll take, leave;

    if (parity) {
        // If parity is true, we can take the current element.
        take = v[i] + exp(i + 1, !parity, n); // We need to not take the next element
    } else {
        // If parity is false, we can't take the current element as it conflicts with the previous one.
        take = 0;
    }

    // If parity is true, we can't leave the current element.
    leave = exp(i + 1, parity, n);

    return dp[i][parity] = max(take, leave);
}

void solve() {
    cin >> n;
    vector<ll> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << exp(0, true, n) << '\n';
}

int main() {
    Youssef;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}