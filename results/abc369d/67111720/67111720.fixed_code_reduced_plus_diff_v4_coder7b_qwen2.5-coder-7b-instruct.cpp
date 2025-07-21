#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // Initialize DP arrays
    vector<ll> dp_e(2), dp_o(2);
    
    rep(i, n) {
        if (i % 2 == 0) {
            dp_e[1] = (dp_e[1] + a[i]) % MOD;
            dp_e[0] = (max(dp_o[0], dp_o[1]) + a[i]) % MOD;
        } else {
            dp_o[1] = (dp_o[1] + a[i]) % MOD;
            dp_o[0] = (max(dp_e[0], dp_e[1]) + a[i]) % MOD;
        }
    }

    cout << (max(dp_e[0], dp_e[1]) + max(dp_o[0], dp_o[1])) % MOD << endl;

    return 0;
}