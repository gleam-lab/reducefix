#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    rep(i, n) {
        cin >> h[i];
        ll full_six = h[i] / 6;
        ll remainder = h[i] % 6;
        if (remainder < 3) {
            ans += full_six * 6 + remainder;
        } else {
            ans += full_six * 6 + 3;
        }
    }
    cout << ans << endl;
}