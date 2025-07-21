#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;

ll v[N];
ll dp[N][2];

ll exp(int i, bool parity) {
    if (i == n)
        return 0;
    ll &result = dp[i][parity];
    if (result != -1)
        return result;

    ll take = exp(i + 1, !parity) + (parity ? v[i] : 2 * v[i]);
    ll leave = exp(i + 1, parity);
    result = max(take, leave);
    return result;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << exp(0, 1) << '\n';
}

int main() {
    Youssef;
    int q = 1;
    cin >> q;
    while (q--)
        solve();
    return 0;
}