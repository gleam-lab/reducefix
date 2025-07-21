#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0; i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    for (ll i = 0; i < n; ) {
        ll health = h[i];
        if (health == 0) {
            i++;
            continue;
        }
        if (health % 3 == 0) {
            ans += health / 3;
            h[i] = 0;
            i++;
        } else {
            ans += (health / 3) * 3 + 3;
            health -= health / 3 * 3 + 3;
            h[i] = health;
        }
    }

    cout << ans << endl;
}