#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007
const int N = 1e5 + 5;

ll dp[N][2];

ll exp(int i = 0, bool parity = 1) {

    if (i == -1)
        return 0;

    ll& res = dp[i][parity];
    if (res != -1)
        return res;

    ll take = exp(i + 1, !parity);
    if (parity)
        take += v[i];
    else
        take += 2 * v[i];

    res = take;

    // No need to calculate leave if parity is not true, as that would just give doubled value
    if (!parity) {
        res = max(res, exp(i + 1, parity));
    }

    return res;
}

void solve() {
    cin >> n;
    vector<ll> v(n);
    for (ll& x : v)
        cin >> x;

    memset(dp, -1, sizeof dp);
    cout << exp(n - 1) << "\n";
}

int main() {
    Youssef
    int q = 1;
    if (cin >> q) {
        while (q--)
            solve();
    }
    return 0;
}