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
        // Calculate the number of full attacks of 3 damage
        ans += (h[i] + 2) / 3; // This is equivalent to ceil(h[i] / 3)
        // If the remainder after full attacks is less than 3, attack once with 1 damage
        if (h[i] % 3 != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}