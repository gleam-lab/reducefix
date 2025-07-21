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
        // Calculate the number of full attacks (each reducing health by 3)
        ans += h[i] / 3;
        // Calculate the remaining health after full attacks
        ll remaining_health = h[i] % 3;
        // Calculate the number of additional attacks needed for the remaining health
        if (remaining_health == 1) {
            ans += 1;  // One more attack needed if remaining health is 1
        } else if (remaining_health == 2) {
            ans += 2;  // Two attacks needed if remaining health is 2
        }
    }
    cout << ans << endl;
}