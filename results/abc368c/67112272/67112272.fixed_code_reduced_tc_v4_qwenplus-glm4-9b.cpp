#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        // Calculate how many full sets of 3 hits are needed
        ll full_sets = h[i] / 3;
        // Calculate remaining health after full sets of 3 hits
        ll remaining_health = h[i] % 3;

        // Add the number of full sets of 3 hits to the answer (each set increases T by 3)
        ans += full_sets * 3;

        // If there's remaining health, we need to increase T by 1 for each hit
        if (remaining_health > 0) {
            ans += remaining_health;
        }
    }

    cout << ans << endl;
}